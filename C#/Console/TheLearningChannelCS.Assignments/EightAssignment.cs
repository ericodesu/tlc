using TheLearningChannelCS.Handlers;
using TheLearningChannelCS.Common.Interfaces;
using TheLearningChannelCS.Questions.EigthAssignment;
using System.Collections.Generic;

namespace TheLearningChannelCS.Assignments
{
    public class EigthAssignment : IAssignment
    {
        private static readonly List<string> MENU_TITLES = new() { "QUESTIONS" };
        private static readonly List<string> AVAILABLE_QUESTIONS = new() { "q1" };

        public IQuestion GetQuestion(string questionName)
        {
            UIHandler.ClearBuffer();

            switch (questionName)
            {
                case "q1":
                    return new FirstQuestion();

                default:
                    return null;
            }
        }

        public void ExecAssignment()
        {
            string questionName = UIHandler.RenderMenu(MENU_TITLES, AVAILABLE_QUESTIONS);

            AssignmentHandler.HandleQuestionExecution(GetQuestion(questionName));
        }
    }
}
