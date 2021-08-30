using TheLearningChannelCS.Common.Interfaces;
using TheLearningChannelCS.Handlers;

namespace TheLearningChannelCS.Questions.ThirtenthAssignment
{
    internal class CovidDataModel
    {
        public int Day { get; set; }

        public int Month { get; set; }

        public int Year { get; set; }

        public int Deaths { get; set; }

        public int DeathsAccumulated { get; set; }

        public int Cases { get; set; }

        public int CasesAccumulated { get; set; }
    }

    public class FirstQuestion : IQuestion
    {
        private static List<CovidDataModel> GetCovidData()
        {
            List<string[]> csvFormatedData = ExternalFilesHandler.GetCSVFormatedData(ExternalFilesHandler.GetTextReader("\\ThirtheenthAssignment\\Covid19VicosaMG.csv"));

            List<CovidDataModel> covidDataModelList = new();

            foreach (string[] strArray in csvFormatedData)
            {
                covidDataModelList.Add(new CovidDataModel()
                {
                    Day = Convert.ToInt32(strArray[0]),
                    Month = Convert.ToInt32(strArray[1]),
                    Year = Convert.ToInt32(strArray[2]),
                    Deaths = Convert.ToInt32(strArray[3]),
                    DeathsAccumulated = Convert.ToInt32(strArray[4]),
                    Cases = Convert.ToInt32(strArray[5]),
                    CasesAccumulated = Convert.ToInt32(strArray[6])
                });
            }

            return covidDataModelList;
        }

        private static void RenderCoviDataTable(List<CovidDataModel> covidData)
        {
            Console.WriteLine("Month/Year   Cases  Deaths");

            foreach (CovidDataModel covidDataModel in covidData)
            {
                Console.WriteLine($"{covidDataModel.Month, 2:D2}/{covidDataModel.Year, 4}\t      {covidDataModel.Cases, 4}    {covidDataModel.Deaths, 3}");
            }
        }

        private static List<int> GetCovidDataDateRage(List<CovidDataModel> codivData, string dateRealm)
        {
            List<int> dateRange = new();

            switch (dateRealm.ToUpper())
            {
                case "YEAR":
                    codivData.ForEach(data =>
                    {
                        if (dateRange.Contains(data.Year) == false)
                        {
                            dateRange.Add(data.Year);
                        }
                    });

                    break;

                case "MONTH":
                    codivData.ForEach(data =>
                    {
                        if (dateRange.Contains(data.Month) == false)
                        {
                            dateRange.Add(data.Month);
                        }
                    });

                    break;

                case "DAY":
                    codivData.ForEach(data =>
                    {
                        if (dateRange.Contains(data.Day) == false)
                        {
                            dateRange.Add(data.Day);
                        }
                    });

                    break;

                default:
                    break;
            }

            return dateRange;
        }

        private static List<CovidDataModel> GetCodivDataDateRange(List<CovidDataModel> codivData)
        {
            List<CovidDataModel> covidDataDateRange = new();

            GetCovidDataDateRage(codivData, "YEAR").ForEach(currentYear =>
            {
                List<CovidDataModel> yearCovidData = codivData.Where(_ => _.Year == currentYear).ToList();

                GetCovidDataDateRage(yearCovidData, "MONTH").ForEach(currentMonth =>
                {
                    List<CovidDataModel> monthCovidData = codivData.Where(_ => _.Month == currentMonth).ToList();

                    CovidDataModel dataBetweenRange = new();

                    GetCovidDataDateRage(monthCovidData, "DAY").ForEach(currentDay =>
                    {
                        dataBetweenRange.Year = currentYear;
                        dataBetweenRange.Month = currentMonth;
                        dataBetweenRange.Day = currentDay;

                        List<CovidDataModel> list = yearCovidData.Where(_ => _.Year == currentYear && _.Month == currentMonth && _.Day == currentDay).ToList();

                        dataBetweenRange.Deaths += list[0].Deaths;
                        dataBetweenRange.DeathsAccumulated += list[0].DeathsAccumulated;
                        dataBetweenRange.Cases += list[0].Cases;
                        dataBetweenRange.CasesAccumulated += list[0].CasesAccumulated;
                    });

                    covidDataDateRange.Add(dataBetweenRange);
                });
            });

            return covidDataDateRange;
        }

        private static int GetUserDateInput(List<int> dateRange, string dateRealm)
        {
            int dateInput = -1;

            bool UserChoiceRestrainer(string userInput) => Int32.Parse(userInput) >= dateRange[0] && Int32.Parse(userInput) <= dateRange[^1];

            if (dateRange != null && dateRange.Count > 0)
            {
                string errorMessage = "Out of bounds date, please try again";

                switch (dateRealm.ToUpper())
                {
                    case "YEAR":
                        dateInput = Int32.Parse(InputHandler.GetUserRestrainedInput(
                            $"Please insert the Year ({dateRange[0]} - {dateRange[^1]}): ",
                            errorMessage,
                            UserChoiceRestrainer
                        ));

                        break;

                    case "MONTH":
                        dateInput = Int32.Parse(InputHandler.GetUserRestrainedInput(
                            $"Please insert the Month ({dateRange[0]} - {dateRange[^1]}): ",
                            errorMessage,
                            UserChoiceRestrainer
                        ));
                        break;

                    case "DAY":
                        dateInput = Int32.Parse(InputHandler.GetUserRestrainedInput(
                            $"Please insert the Day ({dateRange[0]} - {dateRange[^1]}): ",
                            errorMessage,
                            UserChoiceRestrainer
                        ));

                        break;

                    default:
                        break;
                }
            }

            return dateInput;
        }

        private static int GetTargetDataDateTraverseCount(List<CovidDataModel> targetDateList, CovidDataModel targetDateData)
        {
            int traverseCount = 7;

            for (int i = 0; i < targetDateList.Count; ++i)
            {
                CovidDataModel targetDate = targetDateList[i];

                if (targetDate.Year == targetDateData.Year && targetDate.Month == targetDateData.Month && targetDate.Day == targetDateData.Day && i <= 6)
                {
                    traverseCount = i;
                }    
            }

            return traverseCount;
        }

        private static List<double> GetCovidDataDateMovingAverages(List<CovidDataModel> targetList, CovidDataModel targetData)
        {
            List<double> doubleList = new();

            int dateTraverseCount = GetTargetDataDateTraverseCount(targetList, targetData);

            int casesMovingAverage = 0;
            int deathsMovingAverage = 0;

            for (int i = 0; i < targetList.Count; ++i)
            {
                CovidDataModel target = targetList[i];

                if (target.Year == targetData.Year && target.Month == targetData.Month && target.Day == targetData.Day)
                {
                    for (int j = i; j > i - dateTraverseCount; --j)
                    {
                        casesMovingAverage += targetList[j].Cases;
                        deathsMovingAverage += targetList[j].Deaths;
                    }
                }
            }

            doubleList.Add(casesMovingAverage / dateTraverseCount);
            doubleList.Add(deathsMovingAverage / dateTraverseCount);

            return doubleList;
        }

        public void ExecQuestion()
        {
            List<CovidDataModel> covidData = GetCovidData();

            List<CovidDataModel> codivDataDateRange = GetCodivDataDateRange(covidData);

            Console.WriteLine("This question analises the evolution regarding the COVID-19 cases and deaths at Viçosa-MG/Brazil");

            RenderCoviDataTable(codivDataDateRange);

            CovidDataModel covidLatestData = codivDataDateRange[^1];

            Console.WriteLine($"At the last month it was considered {covidLatestData.Day}  days");

            string tryAgainText = "Do you want to find the moving average of a specific date";

            bool willTryAgain = true;

            while (willTryAgain)
            {
                int currentYear = GetUserDateInput(GetCovidDataDateRage(codivDataDateRange, "YEAR"), "YEAR");

                List<CovidDataModel> list1 = covidData.Where(_ => _.Year == currentYear).ToList();

                int currentMonth = GetUserDateInput(GetCovidDataDateRage(list1, "MONTH"), "MONTH");

                List<CovidDataModel> list2 = list1.Where(_ => _.Month == currentMonth).ToList();

                int currentDay = GetUserDateInput(GetCovidDataDateRage(list2, "DAY"), "DAY");

                List<CovidDataModel> list3 = list2.Where(_ => _.Day == currentDay).ToList();

                List<double> dateMovingAverages = GetCovidDataDateMovingAverages(covidData, list3[0]);

                string movingAverageFormatting = "{0:0.00}";

                string casesMovingAverage = string.Format(movingAverageFormatting, dateMovingAverages[0]);
                string dathsMovingAverage = string.Format(movingAverageFormatting, dateMovingAverages[1]);

                Console.WriteLine($"At the {list3[0].Day, 2:D2}/{list3[0].Month, 2:D2}/{list3[0].Year, 2:D2} the moving average of cases was: {casesMovingAverage}");
                Console.WriteLine($"\t     and the moving average of deaths was: {dathsMovingAverage}");

                willTryAgain = InputHandler.GetUserTryAgainInput(tryAgainText);
            }
        }
    }
}
