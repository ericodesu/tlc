using System;
using TheLearningChannelCS.Handlers;

namespace TheLearningChannelCS.Assignments
{
    public class FifthAssignment
    {
        private const int MIN_USER_CHOICE = 1;
        private const int MAX_USER_CHOICE = 100;

        public static void ExecAssignment()
        {
            UIHandler.RenderMenu();

            bool willTryAgain = true;

            while (willTryAgain)
            {
                int userChoice = 0;
                int tryCount = 1;
                int tryMinChoice = MIN_USER_CHOICE;
                int tryMaxChoice = MAX_USER_CHOICE;

                var randomGenerator = new Random();

                int sortedNumber = randomGenerator.Next(MIN_USER_CHOICE, MAX_USER_CHOICE);

                Console.WriteLine($"Será sorteado um número de {MIN_USER_CHOICE} e {MAX_USER_CHOICE} e você deverá descobrir qual... !");

                while (userChoice != sortedNumber)
                {
                    if (userChoice != sortedNumber)
                    {
                        while (userChoice < tryMinChoice || userChoice > tryMaxChoice)
                        {
                            bool UserChoiceRestrainer(string userInput) => Int32.Parse(userInput) > tryMinChoice && Int32.Parse(userInput) < tryMaxChoice;

                            userChoice = Int32.Parse(InputHandler.GetUserRestrainedInput(
                                "Qual seu palpite? ",
                                $"Palpite inválido ! Invervalo:[{tryMinChoice}, {tryMaxChoice}]",
                                (Func<string, bool>)UserChoiceRestrainer
                            ));
                        }

                        string userChoiceStatus = userChoice < sortedNumber ? "maior" : "menor";

                        Console.WriteLine($"Dica número {tryCount} o número sorteado é {userChoiceStatus} que {userChoice}.");

                        if (userChoice < sortedNumber)
                        {
                            tryMinChoice = userChoice + 1;
                        }
                        else
                        {
                            tryMaxChoice = userChoice - 1;
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
