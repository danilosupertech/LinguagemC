#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <stddef.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define DATABASE_FILE "contacts.db"

/**
 * @brief Representa um contato.
 * @brief Represents a contact.
 */
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

// API functions

void cm_init(void); // abre/cria base de dados
void cm_close(void); // fecha base de dados
Contact cm_add_contact(const Contact *c); // adiciona contato
int cm_edit_contact(int id, const Contact *c); // edita por ID
int cm_delete_contact(int id); // exclui por ID
size_t cm_count_contacts(void); // conta contatos
Contact *cm_load_all_contacts(size_t *n); // carrega todos
void cm_print_contact(const Contact *c); // imprime contato
void cm_free_contacts(Contact *list); // libera vetor

#endif // CONTACT_MANAGER_H
