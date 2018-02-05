/*
** command_utils.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun 21 17:37:01 2017 Hugo Baldassin
** Last update Fri Jun 30 13:12:15 2017 Hugo Baldassin
*/

#include 	<string.h>
#include 	"utils.h"
#include 	"commands.h"

t_command_type	is_a_command(char const *str)
{
  unsigned int	i;
  static char	*cmds[12] =
    {
      "Forward",
      "Right",
      "Left",
      "Look",
      "Inventory",
      "Broadcast",
      "Connect_nbr",
      "Fork",
      "Eject",
      "Take",
      "Set",
      "Incantation"
    };

  i = 0;
  while (i < 12 && str)
    {
      if (!strcmp(str, cmds[i]))
	return ((t_command_type)i);
      i++;
    }
  return (UNDEF);
}

unsigned int	get_nb_commands(t_player *player)
{
  unsigned int	i;
  t_command	*tmp;

  i = 0;
  tmp = player->cmd_list;
  while (tmp)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}

char		*get_arg(char const *strcmd)
{
  char		*arg;

  arg = NULL;
  while (*strcmd != ' ' && *strcmd != '\0')
    strcmd++;
  if (*strcmd == ' ')
  {
    while (*strcmd == ' ' && *strcmd)
      strcmd++;
    if (*strcmd)
      arg = mstrdup(strcmd);
  }
  return (arg);
}

char		*get_cmd(char const *strcmd)
{
  char		*cmd;
  char const	*end;

  end = strcmd;
  cmd = NULL;
  while (*end != ' ' && *end != '\0')
    end++;
  if (end != strcmd)
  {
    cmd = myalloc(end - strcmd + 1);
    strncpy(cmd, strcmd, end - strcmd);
    cmd[end - strcmd] = 0;
  }
  return (cmd);
}
