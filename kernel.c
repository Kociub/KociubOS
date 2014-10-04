void kmain(void)
{
	char *str = "--- KociubOS ---";
	char *vidptr = (char*)0xb8000; 	//video memory start.
	unsigned int i = 0;
	unsigned int j = 0;

	//clear all
	while(j < 80 * 25 * 2) {
		//blank character
		vidptr[j] = ' ';
		//attribute-byte: light grey on black screen	
		vidptr[j+1] = 0x02; 		
		j = j + 2;
	}

	j = 0;

	while(str[j] != '\0') {
		vidptr[i] = str[j];
		vidptr[i+1] = 0x02;
		++j;
		i = i + 2;
	}

	return;
}
