#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DBG(x) (fprintf(stderr, "%s\n", (x)))
#define isdigit(x) ((x) >= '0' && (x) <= '9')

int main()
{
	char str[2333] = {0};
	scanf("%[^\n]", str);
	printf("%s\n", str);
	bool hasSign = false, gotDot = false, gotDigit = false, exp = false;
	int len, i = 0;
	len = strlen(str);
	bool isOK = true;
	while (i < len)
	{
		char ch = str[i];
		if (isdigit(ch))
		{
			gotDigit = true;
		}
		else if (ch == '.')
		{
			if (!exp)
			{
				if (!gotDot)
				{
					gotDot = true;
				}
				else
				{
					DBG("multidot");
					isOK = false;
					break;
				}
			}
			else
			{
				DBG("dot in exp");
				isOK = false;
				break;
			}
		}
		else if (ch == 'e')
		{
			if (!exp)
			{
				if (!gotDigit)
				{
					DBG("no digit before exp");
					isOK = false;
					break;
				}
				exp = true;
				hasSign = false;
				gotDigit = false;
			}
			else
			{
				DBG("multiexp");
				isOK = false;
				break;
			}
		}
		else if (ch == '-' || ch == '+')
		{
			if (!hasSign)
			{
				hasSign = true;
			}
			else
			{
				DBG("multisign");
				isOK = false;
				break;
			}
		}
		else
		{
			DBG("invalid char");
			isOK = false;
			break;
		}
		++i;
	}
	if (isOK && !gotDigit)
	{
		DBG("no digit");
		isOK = false;
	}
	printf("isok: %d\n", isOK);
	return 0;
}