#include<stdio.h>
#include<assert.h>
char *my_strcpy(char *dest, const char *src) {
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while ((*dest++ = *src++));
	return ret;
}
char *my_strcat(char *dest, const char *src) {
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest) {
		dest++;
	}
	while ((*dest++ = *src++));
	return ret;
}
char *my_strstr(const char *str1, const char *str2) {
	assert(str1);
	assert(str2);
	char *cp = (char *)str1;
	char *substr = (char *)str2;
	char *s1 = NULL;
	if (*str2 == '\0')
		return NULL;
	while (*cp) {
		s1 = cp;
		substr = str2;
		while (*s1 && *substr && (*s1 == *substr)) {
			s1++;
			substr++;
		}
		if (*substr == '\0')
			return cp;
		cp++;
	}
}
int my_strcmp(const char *src, const char *dest) {
	int ret = 0;
	assert(src != NULL);
	assert(dest != NULL);
	while (!(ret = *(unsigned char *)src - *(unsigned char *)dest) && *dest)
		++src, ++dest;
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;
	return ret;
}
void *memcpy(void *dst, const void *src, size_t count) {
	void *ret = dst;
	assert(dst);
	assert(src);
	while (count--) {
		*(char *)dst = *(char *)src;
		dst = (char *)dst + 1;
		src = (char *)src + 1;
	}
	return ret;
}
int main() {
	char a[20] = "abcdefgh";
	char b[10] = "12345";
	my_strcat(a, b);
	puts(a);
	char c[10] = "abcdefg";
	char f[10] = "abcdefg";
	char d[3] = "bc";
	my_strcpy(c, b);
	puts(c);
	printf("%s\n", my_strstr(f, d));
	char g[10] = "abcdfg";
	printf("%d\n", my_strcmp(f, g));
	system("pause");
	return 0;
}