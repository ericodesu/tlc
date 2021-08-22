using System.Collections.Generic;
using TheLearningChannelCS.Handlers;
using TheLearningChannelCS.Common.Interfaces;
using TheLearningChannelCS.Assignments;

namespace TheLearningChannelCS.App
{
    class Program
    {
        private static readonly List<string> MENU_TITLES = new() { "MENU" };
        private static readonly List<string> MENU_OPTIONS = new() { "p5", "p8", "p9", "p10", "p13" };

        private static IAssignment GetAssignment(string assignmentName)
        {
            switch (assignmentName)
            {
                case "p5":
                    return new FifthAssignment();

                case "p8":
                    return new EigthAssignment();

                case "p9":
                    return new NinthAssignment();

                case "p10":
                    return new FifthAssignment();

                case "p13":
                    return new FifthAssignment();

                default:
                    return null;
            }
        }

        static void Main(string[] args)
        {
            while (true)
            {
                string assignmentName = UIHandler.RenderMenu(MENU_TITLES, MENU_OPTIONS);

                GetAssignment(assignmentName).ExecAssignment();
            }
        }
    }
}
