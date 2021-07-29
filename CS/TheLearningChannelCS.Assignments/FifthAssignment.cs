﻿using TheLearningChannelCS.Handlers;
using TheLearningChannelCS.Common.Interfaces;
using TheLearningChannelCS.Questions.FifthAssignment;
using System.Collections.Generic;

namespace TheLearningChannelCS.Assignments
{
    public class FifthAssignment : IAssignment
    {
        private static readonly List<string> MENU_TITLES = new() { "MENU", "QUESTIONS" };
        private static readonly List<string> AVAILABLE_QUESTIONS = new() { "q1", "q2" };

        public IQuestion GetQuestion(string questionName)
        {
            switch (questionName)
            {
                case "q1":
                    return new FirstQuestion();

                case "q2":
                    return new FirstQuestion();

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
