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
                bool UserChoiceRestrainer(string userInput) => Int32.Parse(userInput) > tryMinChoice && Int32.Parse(userInput) < tryMaxChoice;

                userChoice = Int32.Parse(InputHandler.GetUserRestrainedInput(
                    "Qual seu palpite? ",
                    $"Palpite inválido ! Invervalo:[{tryMinChoice}, {tryMaxChoice}]",
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

                Console.WriteLine($"Será sorteado um número de {MIN_USER_INPUT} e {MAX_USER_INPUT} e você deverá descobrir qual... !");

                while (userInput != sortedNumber)
                {
                    if (userInput != sortedNumber)
                    {
                        userInput = GetUserChoice(userInput, tryMinInput, tryMaxInput);

                        string userChoiceStatus = userInput < sortedNumber ? "maior" : "menor";

                        Console.WriteLine($"Dica número {tryCount} o número sorteado é {userChoiceStatus} que {userInput}.");

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

                Console.WriteLine($"Número sorteado: {sortedNumber}");
                Console.WriteLine($"Voce acertou na {tryCount}a tentativa");
                Console.Write("Deseja jogar de novo? (S/N): ");

                willTryAgain = InputHandler.GetUserTryAgainInput(Console.ReadKey().ToString());
            }
        }
    }
}