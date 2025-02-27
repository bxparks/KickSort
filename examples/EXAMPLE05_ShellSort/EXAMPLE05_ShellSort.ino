/*
 * FILENAME: EXAMPLE05_ShellSort.ino
 * AUTHOR:   Orlando S. Hoilett
 * CONTACT:  orlandohoilett@gmail.com
 * VERSION:  1.1.0
 * 
 * 
 * AFFILIATIONS
 * Linnes Lab, Weldon School of Biomedical Engineering,
 * Purdue University, West Lafayette, IN 47907
 * 
 * 
 * DESCRIPTION
 * Basic test of the KickSort class to evaluate shellSort function.
 * 
 * This library is built from aggregating and modifying different sorting
 * implementations from various other GitHub users including: robtillaart
 * (especially), emilv, luisllamasbinaburo, and dndubins. Thanks!
 * 
 * 
 * UPDATES
 * Version 1.0.0
 * 2020/08/22:2000> (UTC-5)
 *            - Initiated.
 * Version 1.1.0
 * 2020/08/26:2335> (UTC-5)
 *            - Updated comments.
 * 
 * 
 * DISCLAIMER
 * Linnes Lab code, firmware, and software is released under the
 * MIT License (http://opensource.org/licenses/MIT).
 * 
 * The MIT License (MIT)
 * 
 * Copyright (c) 2020 Linnes Lab, Purdue University
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */


#include "KickSort.h"


const uint16_t samples = 200;
//input array from 1 to 100
uint16_t input[samples] = { 3, 53, 70, 56, 18, 85, 27, 14, 37, 94, 9, 55, 40, 60, 52, 61, 15, 65, 13, 8, 57, 97, 69, 4, 35, 82, 22, 73, 59, 68, 78, 24, 21, 36, 71, 80, 74, 39, 17, 12, 29, 76, 49, 51, 30, 90, 88, 2, 84, 50, 62, 28, 77, 43, 5, 16, 58, 26, 32, 34, 1, 75, 66, 95, 38, 89, 67, 87, 100, 54, 92, 81, 25, 83, 46, 33, 23, 45, 96, 99, 79, 48, 11, 31, 7, 6, 19, 91, 93, 44, 47, 98, 86, 41, 63, 20, 72, 10, 42, 64,
3, 53, 70, 56, 18, 85, 27, 14, 37, 94, 9, 55, 40, 60, 52, 61, 15, 65, 13, 8, 57, 97, 69, 4, 35, 82, 22, 73, 59, 68, 78, 24, 21, 36, 71, 80, 74, 39, 17, 12, 29, 76, 49, 51, 30, 90, 88, 2, 84, 50, 62, 28, 77, 43, 5, 16, 58, 26, 32, 34, 1, 75, 66, 95, 38, 89, 67, 87, 100, 54, 92, 81, 25, 83, 46, 33, 23, 45, 96, 99, 79, 48, 11, 31, 7, 6, 19, 91, 93, 44, 47, 98, 86, 41, 63, 20, 72, 10, 42, 64 };


void setup()
{
  Serial.begin(9600);
  while(!Serial); //holds the program until the Serial Monitor is opened


  Serial.println("ShellSort Ascending");
  unsigned long startMicros = micros();
  KickSort<uint16_t>::shellSort(input, samples);
  unsigned long elapsedMicros = micros() - startMicros;
  Serial.print("elapsed micros: ");
  Serial.println(elapsedMicros);

  //print the sorted array
  for(uint16_t i = 0; i < samples; i++)
  {
    Serial.print(i);
    Serial.print(": ");
    Serial.println(input[i]);
  }
  Serial.println();
  Serial.println();


  Serial.println("ShellSort Descending");
  startMicros = micros();
  KickSort<uint16_t>::shellSort(input, samples, KickSort_Dir::DESCENDING);
  elapsedMicros = micros() - startMicros;
  Serial.print("elapsed micros: ");
  Serial.println(elapsedMicros);

  //print the sorted array
  for(uint16_t i = 0; i < samples; i++)
  {
    Serial.print(i);
    Serial.print(": ");
    Serial.println(input[i]);
  }
  Serial.println();
  Serial.println();
  
}

void loop()
{
}
