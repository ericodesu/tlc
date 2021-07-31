using System;
using TheLearningChannelCS.Common.Interfaces;
using TheLearningChannelCS.Handlers;

namespace TheLearningChannelCS.Questions.FifthAssignment
{
    public class SecondQuestion : IQuestion
    {
        private readonly double PI_BASE_NUMBER = 3.141592653589793238462;
        private readonly int ERROR_EXPONENT_MIN_ERROR = 2;
        private readonly int ERROR_EXPONENT_MAX_ERROR = 20;

        public void ExecQuestion()
        {
            bool willTryAgain = true;

            while (willTryAgain)
            {
                Console.WriteLine("The PI value using the Nilakantha series");
                Console.WriteLine("with a error range of (10¯² a 10¯²°).");

                bool UserChoiceRestrainer(string userInput) => Int32.Parse(userInput) >= ERROR_EXPONENT_MIN_ERROR && Int32.Parse(userInput) <= ERROR_EXPONENT_MAX_ERROR;

                int errorExponentValue = Int32.Parse(InputHandler.GetUserRestrainedInput(
                    $"\nDigite um valor ({ERROR_EXPONENT_MIN_ERROR}-{ERROR_EXPONENT_MAX_ERROR}): ",
                    "Valor inválido",
                    UserChoiceRestrainer
                ));

                double erorMaxValue = Math.Pow(10, (-errorExponentValue));

                Console.WriteLine($"You've choosen an error of < {erorMaxValue}");

                bool willShowParcials = InputHandler.GetUserTryAgainInput("Do you want to see the parcial results ?");

                double currentPIValue = 3;

                int iterator = 1;

                double currentErrorValue = Math.Abs(PI_BASE_NUMBER - currentPIValue);

                Console.WriteLine("\tN\tPI value\tError");

                while (currentErrorValue >= erorMaxValue)
                {
                    double summationDividend = (Math.Pow(-1, (iterator + 1)) * 4);
                    int summationDivisor = ((2 * iterator) * ((2 * iterator) + 1) * ((2 * iterator) + 2));

                    double currentSummationInteration = summationDividend / summationDivisor;

                    if (willShowParcials) Console.WriteLine($"\t{iterator}\t{currentPIValue}\t{currentErrorValue}");

                    currentPIValue += currentSummationInteration;

                    currentErrorValue = Math.Abs(PI_BASE_NUMBER - currentPIValue);

                    iterator++;
                }

                Console.WriteLine($"\t{iterator}\t{currentPIValue}\t{currentErrorValue}");

                willTryAgain = InputHandler.GetUserTryAgainInput("Do you want to execute again ?");
            }
        }
    }
}