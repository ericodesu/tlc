using System;
using TheLearningChannelCS.Common.Interfaces;
using TheLearningChannelCS.Handlers;

namespace TheLearningChannelCS.Questions.FifthAssignment
{
    public class FirstQuestion : IQuestion
    {
        private readonly int MIN_USER_INPUT = 1;
        private readonly int MAX_USER_INPUT = 100;

        private static int GetUserChoice(int initialUserChoice, int tryMinChoice, int tryMaxChoice)
        {
            int userChoice = initialUserChoice;

            while (userChoice < tryMinChoice || userChoice > tryMaxChoice)
            {
                bool UserChoiceRestrainer(string userInput) => Int32.Parse(userInput) >= tryMinChoice && Int32.Parse(userInput) <= tryMaxChoice;

                userChoice = Int32.Parse(InputHandler.GetUserRestrainedInput(
                    "Which is your guess? ",
                    $"Invalid guess ! Valid range:[{tryMinChoice}, {tryMaxChoice}]",
                    UserChoiceRestrainer
                ));
            }

            return userChoice;
        }

        public void ExecQuestion()
        {
            bool willTryAgain = true;

            while (willTryAgain)
            {
                int userInput = 0;
                int tryCount = 1;
                int tryMinInput = MIN_USER_INPUT;
                int tryMaxInput = MAX_USER_INPUT;

                var randomGenerator = new Random();

                int sortedNumber = randomGenerator.Next(MIN_USER_INPUT, MAX_USER_INPUT);

                Console.WriteLine($"A number will be drawn from {MIN_USER_INPUT} to {MAX_USER_INPUT} and your task is to find it out...!");

                while (userInput != sortedNumber)
                {
                    userInput = GetUserChoice(userInput, tryMinInput, tryMaxInput);

                    if (userInput != sortedNumber)
                    {
                        string userChoiceStatus = userInput < sortedNumber ? "bigger" : "smaller";

                        Console.WriteLine($"Tip number {tryCount} the drawn number is {userChoiceStatus} than {userInput}.");

                        if (userInput < sortedNumber)
                        {
                            tryMinInput = userInput + 1;
                        }
                        else
                        {
                            tryMaxInput = userInput - 1;
                        }

                        tryCount++;
                    }

                }

                Console.WriteLine($"\nDrawn number: {sortedNumber}");
                Console.WriteLine($"It took you {tryCount} tries");

                willTryAgain = InputHandler.GetUserTryAgainInput("Do you want to play again?");
            }
        }
    }
}