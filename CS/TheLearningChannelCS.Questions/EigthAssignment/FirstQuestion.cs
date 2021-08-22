using System;
using System.Collections.Generic;
using System.Text;
using TheLearningChannelCS.Common.Interfaces;
using TheLearningChannelCS.Handlers;

namespace TheLearningChannelCS.Questions.EigthAssignment
{
    public class FirstQuestion : IQuestion
    {
        private static readonly int ALPHABET_MIN_ASCII_CODE   = (int)'A';
        private static readonly int ALPHABET_MAX_ASCII_CODE   = (int)'z';
        private static readonly int ALPHABET_SPACE_ASCII_CODE = (int)' ';
        private static readonly int ALPHABET_LOWER_UPPER_DIFF = (int)'a' - ALPHABET_MIN_ASCII_CODE;

        private static bool IsCharBetweenBoundaries(int charCode)
        {
            return (charCode >= ALPHABET_MIN_ASCII_CODE && charCode <= ALPHABET_MAX_ASCII_CODE) || (charCode == ALPHABET_SPACE_ASCII_CODE);
        }

        private static char ReverseChar(char character, bool willBeUpperCase)
        {
            int charCode = (int)character;
            int reverseCharCode = charCode;

            if (willBeUpperCase)
            {
                if(charCode >= ALPHABET_MIN_ASCII_CODE)
                {
                    reverseCharCode = ALPHABET_LOWER_UPPER_DIFF + charCode;
                }

            } else
            {
                if (charCode <= ALPHABET_MAX_ASCII_CODE)
                {
                    reverseCharCode = charCode - ALPHABET_LOWER_UPPER_DIFF;
                }
            }

            return (char)reverseCharCode;
        }

        private static string ReverseChunk(string chunk, bool wasChunkReversed)
        {
            char[] chunkList = chunk.ToCharArray();

            List<char> reversedChunk = new ();

            foreach (char chunkChar in chunkList)
            {
                char reversedChar = ReverseChar(chunkChar, !wasChunkReversed);

                if (IsCharBetweenBoundaries(reversedChar))
                {
                    reversedChunk.Add(reversedChar);
                }
                else
                {
                    reversedChunk.Add(chunkChar);
                }
            }

            return new string(reversedChunk.ToArray());
        }

        private static string ReversePhrase(string phrase)
        {
            string reversedPhrase = phrase;

            string[] reversedPhraseChunks = reversedPhrase.Trim().Split(' ');

            bool wasChunkReversed = false;

            for (int i = 0; i < reversedPhraseChunks.Length; i++)
            {
                string currentChunk = reversedPhraseChunks[i];

                reversedPhraseChunks[i] = ReverseChunk(currentChunk, wasChunkReversed);

                wasChunkReversed = !wasChunkReversed;
            }

            reversedPhrase = String.Join(" ", reversedPhraseChunks);

            return reversedPhrase;
        }

        public void ExecQuestion()
        {
            InputHandler.FlushInputBuffer();

            bool willTryAgain = true;

            static bool GetRestrainedPhrase(string phrase) => phrase.Trim().Length > 0;

            while (willTryAgain)
            {
                string originalPhrase = InputHandler.GetUserRestrainedInput(
                    "Type in a phrase: ",
                    "Empty phrase, please try again!",
                    GetRestrainedPhrase
                );

                Console.WriteLine($"Original: {originalPhrase}");

                string reversedPhrase = ReversePhrase(originalPhrase);

                Console.WriteLine($"Modified: {reversedPhrase}");

                willTryAgain = InputHandler.GetUserTryAgainInput("Do you want to run again? ");
            }
        }
    }
}