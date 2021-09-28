using TheLearningChannelCS.Handlers;
using TheLearningChannelCS.Common.Interfaces;
using TheLearningChannelCS.Assignments;

namespace TheLearningChannelCS.App
{
    class Program
    {
        private static readonly List<string> MENU_TITLES = new() { "MENU" };
        private static readonly List<string> MENU_OPTIONS = new() { "a5", "a8", "a9", "a10", "a13" };

        private static IAssignment GetAssignment(string assignmentName)
        {
            switch (assignmentName)
            {
                case "a5":
                    return new FifthAssignment();

                case "a8":
                    return new EigthAssignment();

                case "a9":
                    return new NinthAssignment();

                case "a10":
                    return new TenthAssignment();

                case "a13":
                    return new ThirteenthAssignment();

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
