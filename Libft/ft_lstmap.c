/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:54:30 by mimacdou          #+#    #+#             */
/*   Updated: 2025/02/09 19:10:32 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstn;
	t_list	*noden;
	void	*contentn;

	lstn = NULL;
	while (lst != NULL)
	{
		contentn = f(lst->content);
		noden = ft_lstnew(contentn);
		if (noden == NULL)
		{
			del(contentn);
			ft_lstclear(&lstn, del);
			return (NULL);
		}
		ft_lstadd_back(&lstn, noden);
		lst = lst->next;
	}
	return (lstn);
}
