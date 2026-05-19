//Write your code in this file
#include <stdio.h>
#include <stdbool.h>
//Create a struct called Person with the following members:
//- A char array called namn with a size of 11.
//- An int array called poang with a size of 13.    
struct Person {
    char namn[11];
    int poang[13]; 
};

bool isValidName(char name[] ) {

    bool isValid = true;
  
    for (int i = 0; name[i] != '\0'; i++) {

        //Control that the first letter is uppercase if it's a lowercase letter convert it to uppercase
        if (i == 0 && name[i] >= 'a' && name[i] <= 'z') {
            name[i] = name[i] - ('a' - 'A');
        }
        
         // Other letters lowercase
        if (i > 0 && name[i] >= 'A' && name[i] <= 'Z') {
            name[i] = name[i] + ('a' - 'A');
        }

        //Control that it's only English letters
        if (name[i] < 'a' || name[i] > 'z') {
            isValid = false;
        }

    }
    
    return isValid;

    
}

bool isValidScores(int points[]) {
    //Control that all scores are between 0 and 10
    for (int i = 0; i < 13; i++) {
        //Control that the score is between 0 and 10
        if (points[i] < 0 || points[i] > 10) {
            // If any score is invalid, return false
            return false;
        }
    }
    return true;
} 

float averagePoints(int points[]) {
  
    int sum = 0;
    // Calculate the sum of the scores
    for (int i = 0; i < 13; i++) {
        sum += points[i];
    }
    // Calculate and return the average score
    return (float)sum / 13.0; // Return the average score
}



int main(){

  //Create an array of 5 Person structs called persons.
  struct Person persons[5]; 
  float averageScores[5]; // Array to store average scores for each person
  float totalAverage = 0; // Variable to store the total average score of all persons

  //Get input from the user to fill the array of Person structs. For each person, read their name and their 13 scores.
  for(int i=0; i<5; i++){
    scanf("%10s", persons[i].namn); // Read name with a maximum of 10 characters
   
     isValidName(persons[i].namn);
    
    for(int j=0; j<13; j++){
        // Read each score 
      scanf("%d", &persons[i].poang[j]);  
      // Validate the scores
    }
    isValidScores(persons[i].poang);
    averageScores[i] = averagePoints(persons[i].poang); // Calculate and store the average score for the current person
    totalAverage += averageScores[i]; // Add the average score to the total average
    
  }
   float overallAverage = totalAverage / 5.0; // Calculate the overall average score of all persons 
   int  maxPersonScoreIndex = 0; // Initialize maxPersonScoreIndex with the first person's average score

     for(int i=0; i<5; i++){
            if (averageScores[i] > averageScores[maxPersonScoreIndex]) {
            maxPersonScoreIndex = i; // Update maxPersonScoreIndex if the current person's average score is higher
            }
    }   

    printf("%s\n", persons[maxPersonScoreIndex].namn); // Print the name of the person with the highest average score

   for(int i=0; i<5; i++){

    if (averageScores[i] < overallAverage) // Check if the person's average score is below the overall average    
    {
        printf("%s\n", persons[i].namn); // Print each person's name and their average score
    }    
        
   }

   
  return 0;

}