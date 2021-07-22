using System;

namespace TheLearningChannelCS.Handlers
{
    public class InputHandler
    {
        public static string GetUserRestrainedInput(string questionMessage, string errorMessage, Func<string, bool> InputRestrainEnforcer)
        {
            bool isInputOutOfBoundaries = true;

            string userInput = "";

            while (isInputOutOfBoundaries)
            {
                Console.Write(questionMessage);

                userInput = Console.ReadLine();

                isInputOutOfBoundaries = userInput == "" || !InputRestrainEnforcer(userInput);

                if (isInputOutOfBoundaries)
                {
                    Console.WriteLine(errorMessage);
                }
            }

            return userInput;
        }

        public static bool GetUserTryAgainInput(string userInput)
        {
            string userInputToUpper = userInput.ToUpper();

            return userInputToUpper == "S" || userInputToUpper == "SI" || userInputToUpper == "SIM";
        }
    }
}