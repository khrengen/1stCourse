
int main(int argc, char *argv[])
{
	if (argc != 2){
		fprintf(stdout, "Usage:\n\t./readmat db_file\n");
	}

	FILE *in = fopen(argv[1], "r");

	if (!in) {
		fprintf(stderr, "I/O Error: can`t open file.\n");
		exit(1);
	}