int parse_string_field(char* src, char sep, char** dst, int size)
{
	if (src == NULL) return 0;
	char* p = src;
	while (*p == sep) p++;
	char* start = p;
	int index = 0;
	while (*p != '\0' && index < size)
	{
		if (*p == sep)
		{
			dst[index] = start;
			*p = 0;
			p++;
			start = p;
			index++;
		}
		else
		{
			p++;
		}
	}
	if (*start == '\0')
	{
		return index;
	}

	dst[index] = start;
	index++;
	return index;
}

int main()
{

	char src[] = "/networks/hello/world";
	char* dst[64] = { 0 };
	int len = parse_string_field(src, '/', dst, sizeof(dst) / sizeof(dst[0]));

	for (int i = 0; i < len; ++i)
	{
		printf("%s\r\n", dst[i]);
	}
	getchar();
	return 0;
}