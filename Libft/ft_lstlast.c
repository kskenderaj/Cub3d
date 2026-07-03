/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:04:01 by mimacdou          #+#    #+#             */
/*   Updated: 2025/03/20 15:47:01 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
The code below is practically the same as the code above
the only difference is there is a while instead of a if for the NULL check.
However, despite this it passed moulinette and multiple testers,
as it is logically sound

t_list	*ft_lstlast(t_list *lst)
{
	while (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

Alonzo is testing if it works properly in higher test cases:

A: "even without optimizations it's the same assembly code"  
M: "so... it works?"
A: "yes, as it's all the same to the computer, it shouldn't be,
it really shouldn't be. That is most interesting"

Alonzo and Eden proceed to crash out over how it works,
it's been 10 minutes,
they still can't agree over why it works.

Alonzo thinks that the compilier is doing something it hasn't been asked to do.

Eden thinks it's because it's == to a if in the given circumstances and hence
there is no change but Alzone retorts 
by saying how does it know without running the code.

both sides have a valid argument, personally I have no idea.

This is the best day I've had in awhile ^-^

Eden has used ChatGPD to back up his argument 
but Alonzo left his seat 20 minutes ago and hasn't returned yet
I am eager to see the next developments

Eden is leaving and Alonzo hasn't returned,
he has left me a message to pass onto Alonzo that Eden was right
as the flag Alonzo was using didn't remove all optimisation as he had thought

Alonzo finally returned after several hours
I relayed the message from Eden,
Alonzo believes that he is now definatly correct

they both think they're both correct still and I still I have no idea

It's now the 20th of March 2025,
I understand now
Alonzo was correct, there is still low level optimisation being done
despite the flag Alonzo used to try and compile without optimisation
*/
