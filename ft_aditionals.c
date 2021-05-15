#include "raise_the_terrain.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while ((i < len) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
		dst[i++] = '\0';
	return (dst);
}

char	*ft_strndup(const char *s, size_t n)
{
	char *str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

int	ft_wrdcount(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	i = 0;
	cntr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			cntr++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cntr);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**arr;

	i = 0;
	j = 0;
	k = 0;
	if (!s || !c)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_wrdcount(s, c)) + 1);
	if (arr == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i != j)
			arr[k++] = ft_strndup(s + j, i - j);
	}
	arr[k] = NULL;
	return (arr);
}
