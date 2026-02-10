/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayan <rayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:01:53 by rayan             #+#    #+#             */
/*   Updated: 2026/02/07 18:35:30 by rayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
/**
 * @brief - Locates the first occurrence of a given character in a string.
 * 
 * @param ptr - The string to search.
 * @param c - The character to find (converted to char).
 * @return char* - Pointer to the first occurrence of the character c,
 * 					or NULL if not found.
 */
char	*ft_strchr(const char *ptr, int c);
/**
 * @brief - Creates a new string by concatenating two strings.
 * 
 * @param s1 - First string.
 * @param s2 - Second string.
 * @return char* - A newly allocated string containing s1 followed by s2,
 * 					or NULL if allocation fails.
 */
char	*ft_strjoin(char *s1, char *s2);
/**
 * @brief - Allocates new memory and creates a duplicate of the given string.
 * 
 * @param str - The string to duplicate.
 * @return char* - A pointer to the newly allocated copy of the string,
 * 					or NULL if memory allocation fails.
 */
char	*ft_strdup(const char *str);
/**
 * @brief - Creates a substring from the given string,
 * 			starting at start and up to len characters.
 * 
 * @param s - The original string.
 * @param start - Starting index of the substring.
 * @param len - Maximum length of the substring.
 * @return char* - A newly allocated substring,
 * 					or NULL if memory allocation fails.
 * 					If start is beyond the end of the string,
 * 					returns an empty string.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif