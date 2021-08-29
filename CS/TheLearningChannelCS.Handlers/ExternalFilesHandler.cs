using System.Diagnostics;
using System.Drawing;

namespace TheLearningChannelCS.Handlers
{
    public class ExternalFilesHandler
    {
        private static readonly string PROJECT_BUILD_PATH                  = Directory.GetCurrentDirectory();
        private static readonly string PROJECT_BUILD_TEXT_RESOURCES_PATH  = PROJECT_BUILD_PATH + "\\Resources\\Text";
        private static readonly string PROJECT_BUILD_IMAGE_RESOURCES_PATH = PROJECT_BUILD_PATH + "\\Resources\\Images";
        private static readonly string TEMP_FILE_PREFIX                   = "Temp-";

        private static string GetFileDirectory(string filePath)
        {
            List<string> dividedFilePath = new(filePath.Split("\\"));

            dividedFilePath.RemoveAt(dividedFilePath.Count - 1);

            return string.Join("//", dividedFilePath);
        }

        private static bool IsFileNameValid(string fileName)
        {
            return fileName != null && fileName.Trim().Length > 0;
        }

        private static string ConvertFilePathToTemp(string filePath)
        {
            string convertedFilePath = filePath;

            if (IsFileNameValid(filePath))
            {
                string[] dividedFilePath = convertedFilePath.Split("\\");

                foreach (string pathBlock in dividedFilePath)
                {
                    bool isLastPathBlock = dividedFilePath[^1] == pathBlock;

                    if (isLastPathBlock)
                    {
                        dividedFilePath[^1] = TEMP_FILE_PREFIX + pathBlock;
                    }
                }

                convertedFilePath = string.Join("\\", dividedFilePath);
            }

            return convertedFilePath;
        }

        public static void DeleteTempImage(string imageFilePath)
        {
            if (IsFileNameValid(imageFilePath))
            {
                string fullImageFilePath = ConvertFilePathToTemp(PROJECT_BUILD_IMAGE_RESOURCES_PATH + imageFilePath);

                bool doesFileExists = File.Exists(fullImageFilePath);

                if (doesFileExists)
                {
                    File.Delete(fullImageFilePath);
                }
            }
        }

        public static void SaveTempImage(Bitmap image, string imagePath)
        {
            if (IsFileNameValid(imagePath))
            {
                string imageFilePath = ConvertFilePathToTemp(PROJECT_BUILD_IMAGE_RESOURCES_PATH + imagePath);

                bool directoryExists = Directory.Exists(GetFileDirectory(imageFilePath));

                if (directoryExists)
                {
                    image.Save(imageFilePath);
                }
            }
        }

        public static void RenderImage(string imagePath, bool isATempFile = false)
        {
            string imageFilePath = PROJECT_BUILD_IMAGE_RESOURCES_PATH + imagePath;

            if (isATempFile)
            {
                imageFilePath = ConvertFilePathToTemp(imageFilePath);
            }

            ProcessStartInfo startInfo = new(@"cmd.exe");

            startInfo.Arguments = "/C " + imageFilePath;

            Process imageRenderer = Process.Start(startInfo);

            imageRenderer.WaitForExit();
        }

        public static Bitmap GetImageBitmap(string imagePath)
        {
            string imageFilePath = PROJECT_BUILD_IMAGE_RESOURCES_PATH + imagePath;

            bool doesFileExists = File.Exists(imageFilePath);

            if (doesFileExists)
            {
                Bitmap imageBitmap = new(imageFilePath);

                return imageBitmap;
            }

            return null;
        }
        public static List<string[]> GetCSVFormatedData(StreamReader fileReader)
        {
            List<string[]> formatedData = new(0);

            while (!fileReader.EndOfStream)
            {
                string line = fileReader.ReadLine();
                string[] values = line.Split(';');

                formatedData.Add(values);
            }

            return formatedData;
        }

        public static StreamReader GetTextReader(string filePath)
        {
            string textFilePath = PROJECT_BUILD_TEXT_RESOURCES_PATH + filePath;

            bool doesFileExists = File.Exists(textFilePath);

            if (doesFileExists)
            {
                var textReader = new StreamReader(textFilePath);

                return textReader;
            }

            return null;
        }
    }
}
