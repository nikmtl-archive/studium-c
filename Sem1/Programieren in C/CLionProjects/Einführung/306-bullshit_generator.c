/* Generate 'bullshit sentences'
✓  TO DO 1: In lines v=, n=, a=, ... rand%12? Why always 12? -> arraysize = 12
✓  TO DO 2: Create more complex sentences e.g. by using more adjectives together or by concatenating several phrases.
✓  TO DO 3: Generalize the 'You should' by allowing other random introductions, e.g. "we have to", "our company must"
✓  TO DO 4: Don't write the output to the screen but copy the whole phrase into a separate string (without using library functions)
   Source of words see: http://dack.com/web/bullshit.html
*/
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
/*e
int main() {
	char verbs[][20] = { "benchmark", "exploit", "facilitate", "generate", "implement", "leverage", "maximize",
						 "mesh", "monetize", "optimize", "orchestrate", "redefine" };
	char nouns[][20] = { "action-items", "applications", "bandwidth", "communities", "e-business", "experiences",
						 "infrastructures", "methodologies", "partnerships", "synergies", "solutions", "technologies" };
	char adjectives[][20] = { "bleeding-edge", "collaborative", "cross-platform", "distributed", "efficient",
							  "global", "holistic", "innovative", "mission-critical", "next-generation", "out-of-the-box", "user-centric" };
	char introductions[][30] = { "You should", "We have to", "Our company must", "It is essential to", "We need to" };
	int number, v, n, a1, a2, intro;

	printf("How much bullshit do you need?");
	scanf("%d", &number);

	char bullshit[number][200];
	for (int i = 0; i < number; i++) {
		v = rand() % 12;
		n = rand() % 12;
		a1 = rand() % 12;
		a2 = rand() % 12;
		intro = rand() % 5;

		sprintf(bullshit[i], "%s %s %s and %s %s %s!", introductions[intro], verbs[v], adjectives[a1], adjectives[a2], nouns[n], verbs[v]);
	}

	// Example of how to use the bullshit array
	for (int i = 0; i < number; i++) {
		printf("Your boss says: %s\n", bullshit[i]);
	}

}
*/

//without using library functions
int main() {
    char verbs[][20] = { "benchmark", "exploit", "facilitate", "generate", "implement", "leverage", "maximize",
                         "mesh", "monetize", "optimize", "orchestrate", "redefine" };
    char nouns[][20] = { "action-items", "applications", "bandwidth", "communities", "e-business", "experiences",
                         "infrastructures", "methodologies", "partnerships", "synergies", "solutions", "technologies" };
    char adjectives[][20] = { "bleeding-edge", "collaborative", "cross-platform", "distributed", "efficient",
                              "global", "holistic", "innovative", "mission-critical", "next-generation", "out-of-the-box", "user-centric" };
    char introductions[][30] = { "You should", "We have to", "Our company must", "It is essential to", "We need to" };
    int number, v, n, a1, a2, intro;

    printf("How much bullshit do you need?");
    scanf("%d", &number);

	srand(time(0));

    while (number > 0) {
        v = rand() % 12;
        n = rand() % 12;
        a1 = rand() % 12;
        a2 = rand() % 12;
        intro = rand() % 5;

        char phrase[200];
        int pos = 0;

    	// Copy
        // Copy introduction
        for (int i = 0; introductions[intro][i] != '\0'; i++) {
            phrase[pos++] = introductions[intro][i];
        }
        phrase[pos++] = ' ';

        // Copy verb
        for (int i = 0; verbs[v][i] != '\0'; i++) {
            phrase[pos++] = verbs[v][i];
        }
        phrase[pos++] = ' ';

        // Copy first adjective
        for (int i = 0; adjectives[a1][i] != '\0'; i++) {
            phrase[pos++] = adjectives[a1][i];
        }
        phrase[pos++] = ' ';

        // Copy "and"
        phrase[pos++] = 'a';
        phrase[pos++] = 'n';
        phrase[pos++] = 'd';
        phrase[pos++] = ' ';

        // Copy second adjective
        for (int i = 0; adjectives[a2][i] != '\0'; i++) {
            phrase[pos++] = adjectives[a2][i];
        }
        phrase[pos++] = ' ';

        // Copy noun
        for (int i = 0; nouns[n][i] != '\0'; i++) {
            phrase[pos++] = nouns[n][i];
        }
        phrase[pos++] = ' ';

        // Copy verb again
        for (int i = 0; verbs[v][i] != '\0'; i++) {
            phrase[pos++] = verbs[v][i];
        }
        phrase[pos++] = '!';
        phrase[pos] = '\0'; // Null-terminate the string

        printf("Your boss says: %s\n", phrase);
        number = number - 1;
    }
}