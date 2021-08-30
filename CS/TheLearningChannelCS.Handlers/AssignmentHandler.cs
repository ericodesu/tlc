using TheLearningChannelCS.Common.Interfaces;

namespace TheLearningChannelCS.Handlers
{
    public class AssignmentHandler
    {
        public static void HandleQuestionExecution(IQuestion question)
        {
            if (question != null)
            {
                question.ExecQuestion();

                UIHandler.RenderExecutionFinalMessage();
            }
        }
    }
}
