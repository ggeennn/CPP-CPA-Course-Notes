//////////////clean buffer///////////////

1.1）	getchar (from stdin)

	while (getchar() != '\n');  // 跳过直到换行符
	while (getchar() != EOF);  // 跳过直到文件末尾
 
1.2）	fgetc (from file)

	while (fgets(line, sizeof(line), fp)) {  
 
 	//check if not reading the whole line
		if(strchr(line,'\n') == NULL && strlen(line) == sizeof(line)-1){
			int ch;
			do{
				ch = fgetc(fp);
			}while(ch != '\n' && ch != EOF); // clean up buffer
		}
	}
