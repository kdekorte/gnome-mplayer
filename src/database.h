/*
 * database.h
 *
 * Copyright (C) 2012 - Kevin DeKorte
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _DATABASE_H
#define _DATABASE_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef LIBGDA_ENABLED

#include <libgda/libgda.h>
#include <sql-parser/gda-sql-parser.h>
#include "common.h"
#include "support.h"

GdaConnection *open_db_connection();
void close_db_connection(GdaConnection * conn);
void create_tables(GdaConnection * conn);
void delete_tables(GdaConnection * conn);
void run_sql_non_select(GdaConnection * conn, const gchar * sql);
MetaData *get_db_metadata(GdaConnection * conn, const gchar * uri);
void insert_update_db_metadata(GdaConnection * conn, const gchar * uri, const MetaData * data);
void mark_uri_in_db_as_resumable(GdaConnection * conn, const gchar * uri, gboolean resume, gdouble position);
gboolean is_uri_in_db_resumable(GdaConnection * conn, const gchar * uri);
#endif
#endif
