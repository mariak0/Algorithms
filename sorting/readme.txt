/* The goal is to print the elements of the file, with the smallest number appearing first and the largest number appearing last. The first element swaps places with the value 'Minimum' and the last element swaps places with 'Maximum'. The following code is added to perform these actions and the functions of each command are analyzed in comments:

/* Variables 'Maximum' and 'Minimum' for the smallest and largest values respectively, and variable 'l' (helper) for storing and swapping the 'Maximum' and 'Minimum' values with the first and last values respectively */
for (int count = 0; count < i; count++) { // search for Maximum
if (max < numbers[count]) { max = numbers[count]; l = count; } // assign the value of Maximum to l
}
numbers[l] = numbers[i-1]; // Use the new Maximum for the last value
numbers[i-1] = max; // Store the new Maximum in the last element

    for (int count = 0; count < i; count++) { // search for Minimum
        if (min > numbers[count]) { min = numbers[count]; l = count; } // assign the value of Minimum to l
        }
        numbers[l] = numbers[0]; // Use the new Minimum for the first value
        numbers[0] = min;  // Store the new Minimum in the first element
*/
