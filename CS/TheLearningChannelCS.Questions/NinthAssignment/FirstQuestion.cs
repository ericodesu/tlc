using System;
using System.Collections.Generic;

using TheLearningChannelCS.Common.Interfaces;
using TheLearningChannelCS.Handlers;

namespace TheLearningChannelCS.Questions.NinthAssignment
{
    public class FirstQuestion : IQuestion
    {
        private readonly Random randomDevice = new();
 
        private enum MatrixDimensionTypes {
            Row,
            Column,
        };

        private readonly int MIN_USER_INPUT = 2;
        private readonly int MAX_USER_INPUT = 10;
        private readonly int MIN_RANDOM_DRAW_VALUE = 2;
        private readonly int MAX_RANDOM_DRAW_VALUE = 15;

        private Dictionary<MatrixDimensionTypes, int> GenerateMatrixDimensions (string matrixName)
        {
            bool UserChoiceRestrainer(string userInput) => Int32.Parse(userInput) >= MIN_USER_INPUT && Int32.Parse(userInput) <= MAX_USER_INPUT;

            Dictionary<MatrixDimensionTypes, int> matrixDimensions = new(2);

            matrixDimensions.Add(
                MatrixDimensionTypes.Row,
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
            Console.WriteLine(matrixName);

            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    Console.Write($"  {matrix[i, j], 2}");
                }

                Console.WriteLine();
            }
        }

        private static int[,] AddAndCutMatrices(int[,] matrixA, int[,] matrixB)
        {
            int matrixARowSize = matrixA.GetLength(0);
            int matrixAColumnSize = matrixA.GetLength(1);

            int matrixBRowSize = matrixB.GetLength(0);
            int matrixBColumnSize = matrixB.GetLength(1);

            int resultRowSize = matrixARowSize > matrixBRowSize ? matrixBRowSize : matrixARowSize;
            int resultColumnSize = matrixAColumnSize > matrixBColumnSize ? matrixBColumnSize : matrixAColumnSize;

            int[,] result = new int[resultRowSize, resultColumnSize];

            for (int i = 0; i < resultRowSize; i++)
            {
                for (int j = 0; j < resultColumnSize; j++)
                {
                    result[i, j] = matrixA[i, j] + matrixB[i, j];
                }
            }

            return result;
        }

        private static int[,] AddAndKeepMatrices(int[,] matrixA, int[,] matrixB)
        {
            int matrixARowSize    = matrixA.GetLength(0);
            int matrixAColumnSize = matrixA.GetLength(1);

            int matrixBRowSize    = matrixB.GetLength(0);
            int matrixBColumnSize = matrixB.GetLength(1);

            int resultRowSize    = matrixARowSize > matrixBRowSize ? matrixARowSize : matrixBRowSize;
            int resultColumnSize = matrixAColumnSize > matrixBColumnSize ? matrixAColumnSize : matrixBColumnSize;

            int[,] result = new int[resultRowSize, resultColumnSize];

            for (int i = 0; i < resultRowSize; i++)
            {
                for (int j = 0; j < resultColumnSize; j++)
                {
                    int matrixACurrentValue = i >= matrixARowSize || j >= matrixAColumnSize ? 0 : matrixA[i, j];
                    int matrixBCurrentValue = i >= matrixBRowSize || j >= matrixBColumnSize ? 0 : matrixB[i, j];

                    result[i, j] = matrixACurrentValue + matrixBCurrentValue;
                }
            }

            return result;
        }

        public void ExecQuestion()
        {
            Dictionary<MatrixDimensionTypes, int> matrixADimensions = GenerateMatrixDimensions("Matrix A");
            Dictionary<MatrixDimensionTypes, int> matrixBDimensions = GenerateMatrixDimensions("Matrix B");

            int[,] matrixA = new int[matrixADimensions[MatrixDimensionTypes.Row], matrixADimensions[MatrixDimensionTypes.Column]];
            int[,] matrixB = new int[matrixBDimensions[MatrixDimensionTypes.Row], matrixBDimensions[MatrixDimensionTypes.Column]];

            PopulateMatrixWithRandomIntegers(matrixA);
            PopulateMatrixWithRandomIntegers(matrixB);

            RenderMatrix(matrixA, "Matrix A:");
            RenderMatrix(matrixB, "\nMatrix B:");

            int[,] matrixAddAndCut  = AddAndCutMatrices(matrixA, matrixB);
            int[,] matrixAddAndKeep = AddAndKeepMatrices(matrixA, matrixB);

            RenderMatrix(matrixAddAndCut,  "\nAdd A And Cut B:");
            RenderMatrix(matrixAddAndKeep, "\nAdd A And Keep B:");
        }
    }
}
