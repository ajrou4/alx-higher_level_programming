#include "lists.h"

/**
 * reverse_list - reverses the second half of the linked list
 * @head: the head of the list
 * Return: the new head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *current = head, *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

/**
 * is_palindrome - checks if a list is a palindrome
 * @head: the head of the list
 * Return: 1 if true, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return 1; // An empty list or a single-node list is a palindrome

    listint_t *slow = *head, *fast = *head, *second_half, *prev_slow = *head;

    while (fast != NULL && fast->next != NULL)
    {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != NULL) // Odd number of elements, move slow to the middle
        slow = slow->next;

    second_half = reverse_list(slow);
    slow = *head;

    while (second_half != NULL)
    {
        if (slow->n != second_half->n)
        {
            reverse_list(second_half); // Restore the original order
            return 0; // Not a palindrome
        }
        slow = slow->next;
        second_half = second_half->next;
    }

    reverse_list(second_half); // Restore the original order
    return 1; // Palindrome
}

