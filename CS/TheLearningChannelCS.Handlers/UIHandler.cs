using System;
using System.Collections.Generic;

namespace TheLearningChannelCS.Handlers
{
    public class UIHandler
    {
        public static void RenderBoundaryBars(int barCount = 2)
        {
            string boudaryBars = new('=', barCount);

            Console.WriteLine(boudaryBars);
        }

        public static void ClearBuffer()
        {
            Console.Clear();
        }

        public static string RenderMenu(List<string> menuTitles, List<string> menuOptions)
        {
            ClearBuffer();

            int barCount = 28;

            RenderBoundaryBars(barCount);

            menuTitles.ForEach(displayName => Console.WriteLine(displayName));

            Console.WriteLine();

            menuOptions.ForEach(menuOption => Console.WriteLine(menuOption));

            RenderBoundaryBars(barCount);

            bool OptionChoiceRestrainer(string optionChoice) => menuOptions.Exists(_ => _.Equals(optionChoice));

            return InputHandler.GetUserRestrainedInput(
                "Qual opção deseja escolher? ",
                "Opção inválida !",
                (Func<string, bool>)OptionChoiceRestrainer
            );
        }
    }
}