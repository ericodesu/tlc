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

        public static bool GetUserTryAgainInput(string tryAgainText)
        {
            Console.Write($"\n{tryAgainText} (Y/N): ");

            string userInputToUpper = Console.ReadLine().ToUpper();

            return userInputToUpper == "Y"  ||
                   userInputToUpper == "YE" ||
                   userInputToUpper == "YES";
        }
    }
}