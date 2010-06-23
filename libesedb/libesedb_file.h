/*
 * File functions
 *
 * Copyright (c) 2009-2010, Joachim Metz <jbmetz@users.sourceforge.net>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBESEDB_INTERNAL_FILE_H )
#define _LIBESEDB_INTERNAL_FILE_H

#include <common.h>
#include <types.h>

#include <liberror.h>

#include "libesedb_extern.h"
#include "libesedb_io_handle.h"
#include "libesedb_list_type.h"
#include "libesedb_page_tree.h"

#if defined( _MSC_VER ) || defined( __BORLANDC__ )

/* This inclusion is needed otherwise some linkers
 * mess up exporting the legacy functions
 */
#include "libesedb_legacy.h"
#endif

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libesedb_internal_file libesedb_internal_file_t;

struct libesedb_internal_file
{
	/* The database page tree
	 */
	libesedb_page_tree_t *database_page_tree;

	/* The catalog page tree
	 */
	libesedb_page_tree_t *catalog_page_tree;

	/* The file io handle
	 */
	libbfio_handle_t *file_io_handle;

	/* Value to indicate if the file io handle was created inside the library
	 */
	uint8_t file_io_handle_created_in_library;

	/* The io handle
	 */
	libesedb_io_handle_t *io_handle;

	/* The pages vector
	 */
	libfdata_vector_t *pages_vector;

	/* The codepage of the extended ASCII strings
	 */
	int ascii_codepage;

	/* Value to indicate if abort was signalled
	 */
	int abort;
};

LIBESEDB_EXTERN int libesedb_file_initialize(
                     libesedb_file_t **file,
                     liberror_error_t **error );

LIBESEDB_EXTERN int libesedb_file_free(
                     libesedb_file_t **file,
                     liberror_error_t **error );

LIBESEDB_EXTERN int libesedb_file_signal_abort(
                     libesedb_file_t *file,
                     liberror_error_t **error );

LIBESEDB_EXTERN int libesedb_file_open(
                     libesedb_file_t *file,
                     const char *filename,
                     int flags,
                     liberror_error_t **error );

#if defined( HAVE_WIDE_CHARACTER_TYPE )
LIBESEDB_EXTERN int libesedb_file_open_wide(
                     libesedb_file_t *file,
                     const wchar_t *filename,
                     int flags,
                     liberror_error_t **error );
#endif

LIBESEDB_EXTERN int libesedb_file_open_file_io_handle(
                     libesedb_file_t *file,
                     libbfio_handle_t *file_io_handle,
                     int flags,
                     liberror_error_t **error );

LIBESEDB_EXTERN int libesedb_file_close(
                     libesedb_file_t *file,
                     liberror_error_t **error );

int libesedb_file_open_read(
     libesedb_internal_file_t *internal_file,
     liberror_error_t **error );

LIBESEDB_EXTERN int libesedb_file_get_ascii_codepage(
                     libesedb_file_t *file,
                     int *ascii_codepage,
                     liberror_error_t **error );

LIBESEDB_EXTERN int libesedb_file_set_ascii_codepage(
                     libesedb_file_t *file,
                     int ascii_codepage,
                     liberror_error_t **error );

LIBESEDB_EXTERN int libesedb_file_get_format_version(
                     libesedb_file_t *file,
                     uint32_t *format_version,
                     uint32_t *format_revision,
                     liberror_error_t **error );

LIBESEDB_EXTERN int libesedb_file_get_creation_format_version(
                     libesedb_file_t *file,
                     uint32_t *format_version,
                     uint32_t *format_revision,
                     liberror_error_t **error );

LIBESEDB_EXTERN int libesedb_file_get_page_size(
                     libesedb_file_t *file,
                     uint32_t *page_size,
                     liberror_error_t **error );

LIBESEDB_EXTERN int libesedb_file_get_number_of_tables(
                     libesedb_file_t *file,
                     int *number_of_tables,
                     liberror_error_t **error );

LIBESEDB_EXTERN int libesedb_file_get_table(
                     libesedb_file_t *file,
                     int table_entry,
                     libesedb_table_t **table,
                     liberror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

