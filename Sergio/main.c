#include <stdio.h>
#include <unistd.h>
#include <pocketsphinx.h>




char const	*call_to_sphinx(void)
{
    ps_decoder_t *ps;
    cmd_ln_t *config;
    FILE *fh;
    char const *hyp, *uttid;
    int16 buf[512];
    int rv;
    int32 score;

    config = cmd_ln_init(NULL, ps_args(), TRUE,
		         "-hmm", "./en-us",
		         "-lm", "./TAR4998/4998.lm",
	    		 "-dict", "./TAR4998/4998.dic",
		         NULL);
    if (config == NULL)
    {
	    fprintf(stderr, "Failed to create config object, see log for details\n");
	    return (NULL);
    }
    ps = ps_init(config);
    if (ps == NULL) 
    {
	    fprintf(stderr, "Failed to create recognizer, see log for details\n");
	    return (NULL);
    }
    fh = fopen("src.wav", "rb");    //replace file name new.raw with the one that is to be read
    if (fh == NULL)
    {
	    fprintf(stderr, "Unable to open input file \n");
	    return (NULL);
    }
    rv = ps_start_utt(ps);
    while (!feof(fh))
    {
	    size_t nsamp;
	    nsamp = fread(buf, 2, 512, fh);
	    rv = ps_process_raw(ps, buf, nsamp, FALSE, FALSE);
    }
    rv = ps_end_utt(ps);
    hyp = ps_get_hyp(ps, &score);
    printf("Recognized: %s\n", hyp); //remove this printf statement once we know how or where to send off the string 'hyp'
    fclose(fh);
    ps_free(ps);
    cmd_ln_free_r(config);

    return(hyp);
}


int		main(void)
{
	char const *str;

	str = call_to_sphinx();
	printf("%s\n", (char*)str);

	return (0);
}

/*

it will probably be easiest to put this function in as a function call within the real main function that loops every time it gets a new audio file

gcc -o test main.c `pkg-config --cflags --libs pocketsphinx sphinxbase` `pkg-config --cflags --libs sdl2`

recording command 
    "rec -c 1 -L -e signed -b 16 -r 16000 new.raw"

*/
