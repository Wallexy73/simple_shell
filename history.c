#include "shell.h"
#include "history.h"

/**
 *  gethistory - gets the history list
 *  Return: 0 uposon success
 *  get_history_file - gets the history file
 *  @info: parameter struct
 *
 *  Return: allocated string containg history file
 */

HistList **gethistory()
char *get_history_file(info_t *info)
{
	static HistList *hlist;

	return (&hlist);
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * sethist - set hist and value
 * @cmd: command
 * Return: 0 upon success
 * write_history - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */

int sethist(char *cmd)
int write_history(info_t *info)
{
	HistList **hlistroot = gethistory();
	HistList *hlist = *hlistroot;
	HistList *ptr = hlist, *new;

	if (hlist == NULL)
	{
		new = malloc(sizeof(HistList));
		if (new == NULL)
			return (-1);
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;

		new->cmd = _strdup(cmd);
		new->next = NULL;
		*hlistroot = new;
		return (0);
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	if (!filename)
		return (-1);
	
	new = malloc(sizeof(HistList));
	if (new == NULL)
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	new->cmd = _strdup(cmd);
	new->next = NULL;
	ptr->next = new;
	return (0);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * print_hist - prints all elements of listint
 * read_history - reads history from file
 * @info: the parameter struct
 *
 * Return: num of elements
 * Return: histcount on success, 0 otherwise
 */

int print_hist(void)
int read_history(info_t *info)
{
	HistList **hlistroot = gethistory();
	HistList *h = *hlistroot;
	int i;
	int len, numlen;
	char *s, *num;
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	i = 0;
	while (h != NULL)
	{
		len = _strlen(h->cmd);
		s = h->cmd;
		num = itos(i);
		numlen = _strlen(num);
		write(1, num, numlen);
		_putchar(' ');
		write(1, s, len);
		h = h->next;
		i++;
	}
	return (i);
	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY)
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * exit_hist - exit history and copy to file
 * Return: int
 * build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */

int exit_hist(void)
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	int fd;
	char *file = ".simple_shell_history";
	int len;
	char *s;
	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	HistList **hlistroot = gethistory();
	HistList *hlist = *hlistroot;
	HistList *ptr = hlist;
	if (!info->history)
		info->history = node;
	return (0);
}

fd = open(file, O_CREAT | O_RDWR, 0600);
if (fd == -1)
	return (-1);
/**
 * renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (hlist != NULL)
	while (node)
	{
		ptr = hlist->next;
		s = hlist->cmd;
		len = _strlen(s);
		write(fd, s, len);
		free(hlist->cmd);
		free(hlist);
		hlist = ptr;
		node->num = i++;
		node = node->next;
	}

	close(fd);
	return (1);
	return (info->histcount = i);
}
