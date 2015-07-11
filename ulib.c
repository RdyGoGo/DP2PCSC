#include "ulib.h"

int wrap(const char *from, const char tail, char *to)
{
	if(from == NULL || tail == '\0')
		return FALSE;
	int from_str_length = strlen(from) * sizeof(char);
	//sprintf(to, "%c%s%c", head, from, tail);
	strncpy(to, from, from_str_length);
	memset(to + from_str_length, tail, 1);
	return TRUE;
}

int un_wrap(char *str, char *tail)
{
	if (str == NULL) 
		return FALSE;
	size_t tail_position = (strlen(str) - 1) * sizeof(char);
	//*head = *str;
	if (tail != NULL)
		*tail = *(str + tail_position);
	//printf("[unwrap before]%s\n",str);
	memset(str + tail_position, 0, 1);
	//printf("[unwrap settail]%s\n",str);
	//memmove(str, str + 1,tail_position);
	//printf("[unwrap mmove]%s\n",str);
	return TRUE;
}

int compare_wrap(const char *str,char tail)
{
	char tailstr[2] = {tail, 0};
	if (strcspn(str,tailstr) == strlen(str) - 1)
		return TRUE;
	else
		return FALSE;
}
