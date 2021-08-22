using System.Collections.Generic;
using TheLearningChannelCS.Common.Interfaces;
using TheLearningChannelCS.Handlers;
using TheLearningChannelCS.Questions.NinthAssignment;

namespace TheLearningChannelCS.Assignments
{
    public class NinthAssignment : IAssignment
    {
        private static readonly List<string> MENU_TITLES = new() { "QUESTIONS" };
        private static readonly List<string> AVAILABLE_QUESTIONS = new() { "q1", "q2" };

        public IQuestion GetQuestion(string questionName)
        {
            UIHandler.ClearBuffer();

            switch (questionName)
            {
                case "q1":
                    return new FirstQuestion();

                case "q2":
                    return new SecondQuestion();

                default:
                    return null;
            }
        }

        public void ExecAssignment()
        {
            string questionName = UIHandler.RenderMenu(MENU_TITLES, AVAILABLE_QUESTIONS);

            GetQuestion(questionName).ExecQuestion();
        }
    }
}
