using System;
using System.Collections.Generic;
using System.Data.Common;
using TheLearningChannelCS.Common.Interfaces;
using TheLearningChannelCS.Handlers;

namespace TheLearningChannelCS.Questions.NinthAssignment
{
    public class SecondQuestion : IQuestion
    {
        private readonly Random randomDevice = new();

        private enum MatrixDimensionTypes
        {
            Row,
            Column,
        };

        private readonly int MIN_USER_INPUT = 2;
        private readonly int MAX_USER_INPUT = 8;
        private readonly int MIN_RANDOM_DRAW_VALUE = -10;
        private readonly int MAX_RANDOM_DRAW_VALUE =  10;

        private Dictionary<MatrixDimensionTypes, int> GenerateMatrixDimensions(string matrixName, bool willOverrideRowValue = false, int overrideRowValue = 1)
        {
            bool UserChoiceRestrainer(string userInput) => Int32.Parse(userInput) >= MIN_USER_INPUT && Int32.Parse(userInput) <= MAX_USER_INPUT;

            Dictionary<MatrixDimensionTypes, int> matrixDimensions = new(2);

            if (willOverrideRowValue)
            {
                Console.WriteLine($"The row value of the {matrixName} will be {overrideRowValue}");
            }

            matrixDimensions.Add(
                MatrixDimensionTypes.Row,
                willOverrideRowValue ?
                    overrideRowValue
                :
                    Int32.Parse(InputHandler.GetUserRestrainedInput(
                        $"Number of rows at the {matrixName} ({MIN_USER_INPUT} - {MAX_USER_INPUT}): ",
                        "Invalid value!!!",
                        UserChoiceRestrainer
                    ))
            );

            matrixDimensions.Add(
                MatrixDimensionTypes.Column,
                Int32.Parse(InputHandler.GetUserRestrainedInput(
                    $"Number of columns at the {matrixName} ({MIN_USER_INPUT} - {MAX_USER_INPUT}): ",
                    "Invalid value!!!",
                    UserChoiceRestrainer
                ))
            );

            return matrixDimensions;
        }

        private int[,] PopulateMatrixWithRandomIntegers(int[,] matrix)
        {
            int[,] populatedMatrix = matrix;

            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    matrix[i, j] = randomDevice.Next(MIN_RANDOM_DRAW_VALUE, MAX_RANDOM_DRAW_VALUE);
                }
            }

            return populatedMatrix;
        }

        private static void RenderMatrix(int[,] matrix, string matrixName)
        {
            Console.WriteLine($"\n{matrixName}");

            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    Console.Write($"  {matrix[i, j], 4}");
                }

                Console.WriteLine();
            }
        }

        private static int[,] MultiplyMatrices(int[,] matrixA, int[,] matrixB)
        {
            int matrixARowSize = matrixA.GetLength(0);

            int matrixBColumnSize = matrixB.GetLength(1);

            int resultRowSize = matrixARowSize;
            int resultColumnSize = matrixBColumnSize;

            int[,] result = new int[resultRowSize, resultColumnSize];

            for (int i = 0; i < matrixARowSize; i++)
            {
                for (int j = 0; j < matrixBColumnSize; j++)
                {
                    for (int k = 0; k < result.GetLength(1); k++)
                    {
                        int matrixACurrentValue = matrixA[i, k];
                        int matrixBCurrentValue = matrixB[k, j];

                        result[i, j] =+ matrixACurrentValue * matrixBCurrentValue;
                    }
                }
            }

            return result;
        }

        public void ExecQuestion()
        {
            Dictionary<MatrixDimensionTypes, int> matrixADimensions = GenerateMatrixDimensions("Matrix A");
            Dictionary<MatrixDimensionTypes, int> matrixBDimensions = GenerateMatrixDimensions("Matrix B", true, matrixADimensions[MatrixDimensionTypes.Column]);

            int[,] matrixA = new int[matrixADimensions[MatrixDimensionTypes.Row], matrixADimensions[MatrixDimensionTypes.Column]];
            int[,] matrixB = new int[matrixBDimensions[MatrixDimensionTypes.Row], matrixBDimensions[MatrixDimensionTypes.Column]];

            PopulateMatrixWithRandomIntegers(matrixA);
            PopulateMatrixWithRandomIntegers(matrixB);

            RenderMatrix(matrixA, "\nMatrix A:");
            RenderMatrix(matrixB, "Matrix B:");

            int[,] matrixC = MultiplyMatrices(matrixA, matrixB);

            RenderMatrix(matrixC, "Matrix C:");
        }
    }
}
