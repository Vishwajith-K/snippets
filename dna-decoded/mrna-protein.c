#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		fprintf(stderr, "Usage: %s <mRNA code>\n", argv[0]);
		fflush(stderr);
	}
	else {
		struct {
			const char codon[4];
			const char acid;
		} codon_acid_lut[] = {
			#include "codon_acid_lut.h"
		};
		unsigned int i, j, codon_acid_lut_n = sizeof(codon_acid_lut) / sizeof(codon_acid_lut[0]);
		const char *a = argv[1];
		#ifndef IGNORE_START
		i = 0;
		#else
		for (i = 0; a[i] != 0 && a[i + 1] != 0 && a[i + 2] != 0; i += 3) {
			const char anti_codon[4] = {a[i], a[i + 1], a[i + 2], '\0'};
			if (strcmp(anti_codon, "AUG") == 0) break;
		}
		#endif
		for (; a[i] != 0 && a[i + 1] != 0 && a[i + 2] != 0; i += 3) {
			const char anti_codon[4] = {a[i], a[i + 1], a[i + 2], '\0'};
			j = 0;
			while ((j < codon_acid_lut_n) && (strcmp(anti_codon, codon_acid_lut[j].codon) != 0)) { ++j;}
			if (j < codon_acid_lut_n) {
				if (codon_acid_lut[j].acid)
					putchar(codon_acid_lut[j].acid);
				#ifdef IGNORE_END
				else
					goto stop_translation;
				#endif
			}
			else
				putchar('X');
		}
	stop_translation:
		putchar('\n');
		fflush(stdout);
	}
	return 0;
}
