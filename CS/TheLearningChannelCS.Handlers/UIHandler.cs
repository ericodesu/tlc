using System;

namespace TheLearningChannelCS.Handlers
{
    public class UIHandler
    {
        public static void RenderBoundaryBars(int barCount = 2)
        {
            string boudaryBars = new('=', barCount);

            Console.WriteLine(boudaryBars);
        }

        public static void RenderMenu()
        {
            RenderBoundaryBars(10);

            Console.WriteLine("MENU");

            RenderBoundaryBars(10);
        }
    }
}