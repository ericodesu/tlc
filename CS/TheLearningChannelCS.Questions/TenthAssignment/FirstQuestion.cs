using System.Drawing;

using TheLearningChannelCS.Common.Interfaces;
using TheLearningChannelCS.Handlers;

namespace TheLearningChannelCS.Questions.TenthAssignment
{
    public class FirstQuestion : IQuestion
    {
        private static Dictionary<int[], Color> GetMannequinPixelRange(Bitmap mannequinImageBitmap, Color boundaryColor)
        {
            int colorGradeTolerance = 50;

            Dictionary<int[], Color> dictionary = new();

            for (int x = 0; x < mannequinImageBitmap.Width; ++x)
            {
                for (int y = 0; y < mannequinImageBitmap.Height; ++y)
                {
                    Color pixel = mannequinImageBitmap.GetPixel(x, y);

                    if (pixel.R >= boundaryColor.R - colorGradeTolerance &&
                        pixel.R <= boundaryColor.R + colorGradeTolerance &&
                        pixel.G >= boundaryColor.G - colorGradeTolerance &&
                        pixel.G <= boundaryColor.G + colorGradeTolerance &&
                        pixel.B >= boundaryColor.B - colorGradeTolerance &&
                        pixel.B <= boundaryColor.B + colorGradeTolerance)
                    {
                        int[] key = new int[2] { x, y };

                        dictionary.Add(key, pixel);
                    }
                }
            }
            return dictionary;
        }

        private static Bitmap UpdateImagePixelRangeColor(Bitmap image, Dictionary<int[], Color> pixelRange, Color newColor)
        {
            Bitmap bitmap = image;

            foreach (KeyValuePair<int[], Color> keyValuePair in pixelRange)
            {
                int x = keyValuePair.Key[0];
                int y = keyValuePair.Key[1];

                bitmap.SetPixel(x, y, newColor);
            }
            return bitmap;
        }

        public void ExecQuestion()
        {
            string imagePath = "\\TenthAssignment\\Pedestrian.png";

            Bitmap imageBitmap = ExternalFilesHandler.GetImageBitmap(imagePath);

            ExternalFilesHandler.RenderImage(imagePath);

            Dictionary<int[], Color> mannequinPixelRange = GetMannequinPixelRange(imageBitmap, Color.FromArgb(0, 0, 0));

            Bitmap tempImageBitMap = UpdateImagePixelRangeColor(imageBitmap, mannequinPixelRange, Color.FromArgb(0, 255, 0));

            ExternalFilesHandler.SaveTempImage(tempImageBitMap, imagePath);

            ExternalFilesHandler.RenderImage(imagePath, true);

            Thread.Sleep(1000);

            ExternalFilesHandler.DeleteTempImage(imagePath);
        }
    }
}