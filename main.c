#include "header_only.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "common.h"

int main(int argc, char *argv[])
{
	if (argc > 2)
	{
		fprintf(stderr, "Too mach argument\n");
		return (1);
	}
	
	if (argc == 2)
	{
		FILE* dictionary_file = NULL;
		
		if (!(dictionary_file = fopen(argv[argc - 1], "a+t")))
		{
			fprintf(stderr, "Invalid dictionary file: %s", argv[argc - 1]);
			return (1);
		}
		
		load_dictionary(dictionary_file);
		
		fclose(dictionary_file);
	}

	
	start_print(argc == 2 ? argv[argc - 1] : NULL);
	return 0;
}
