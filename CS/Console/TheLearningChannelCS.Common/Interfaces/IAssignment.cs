namespace TheLearningChannelCS.Common.Interfaces
{
    public interface IAssignment
    {
        public void ExecAssignment();

        public IQuestion GetQuestion(string questionName);
    }
}
