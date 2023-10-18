#include "main.h"

/**
 * _strtok - Tokenizer.
 * @str: The string to be tokenized.
 * @_delimiters: String of delimiters foro tokenization.
 * Return: string
 */

string _strtok(string str, string _delimiters)
{
	static string _sStr;
	string _shifter, rv;

	if (str)
		_sStr = str;

	while ((_strchr(_delimiters, *_sStr)) && *_sStr)
	{
		_sStr++;
	}

	if (*_sStr == '\0')
		return (NULL);

	_shifter = _sStr;
	rv = _shifter;

	while (*_shifter)
	{
		if (_strchr(_delimiters, *_shifter))
		{
			if (*_shifter == '\0')
				_sStr = _shifter;
			else
				_sStr = _shifter + 1;

			*_shifter = '\0';

			while (strchr(_delimiters, *_sStr) && *_sStr)
			{
				_sStr++;
			}
			return (rv);
		}
		_shifter++;
	}

	_sStr = _shifter;
	return (rv);
}
