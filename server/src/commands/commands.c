/*
** chan_list.c for myirc in /home/baldas/Prog/repos/tek2/psu/PSU_2016_myirc/src/srv/chan_list
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Mon Jun  5 15:08:47 2017 Hugo Baldassin
** Last update Fri Jun 30 13:11:30 2017 Hugo Baldassin
*/

#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
#include	<stdio.h>
#include	"debug.h"
#include	"frequency.h"
#include	"commands.h"
#include	"utils.h"

static void		free_node(t_command *node)
{
  free(node->arg);
  free(node);
}

static void 		init_time_units(t_command *node, t_command_type type,
					size_t frequency)
{
  static int 		cmds_units[12] =
    {
      7,
      7,
      7,
      7,
      1,
      7,
      0,
      42,
      7,
      7,
      7,
      0
    };

  node->time_units = COMMAND_TIME(cmds_units[type], frequency);
  if (node->time_units == 0)
    node->time_units = 1;
}

t_command		*init_command(char const *strcmd, size_t frequency)
{
  t_command		*cmd;
  char			*scmd;

  cmd = myalloc(sizeof(t_command));
  cmd->type = is_a_command(strcmd);
  cmd->arg = NULL;
  if (cmd->type == UNDEF)
  {
    scmd = get_cmd(strcmd);
    cmd->type = is_a_command(scmd);
    free(scmd);
    cmd->arg = get_arg(strcmd);
  }
  cmd->next = NULL;
  cmd->active = false;
  init_time_units(cmd, cmd->type, frequency);
  CMDLOG("[COMMAND] :: NEW ::\n");
  return (cmd);
}

void			add_command(t_command **list, t_command *node)
{
  t_command		*tmp;

  tmp = (*list);
  if (!tmp)
    (*list) = node;
  else
    {
      while (tmp->next)
    	tmp = tmp->next;
      tmp->next = node;
    }
}

void			pop_command(t_command **list)
{
  t_command		*node;

  assert(*list != NULL);
  node = (*list);
  *list = node->next;
  free_node(node);
}
