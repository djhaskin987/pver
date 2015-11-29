#ifndef __PPM_INSTALL_H__
#define __PPM_INSTALL_H__

/* *Actually* runs all I/O operations having to do
 * with install. In particular:
 *   - Installs package files
 */
int install_package_files(char *package_file, char *package_root_path);


/* put in an errors.h. */
#define PPM_ERR_INVALID_VERSION
#define PPM_ERR_INVALID_NAME

/* Reads information about the project. I/O */
int ppm_project_info_io(ppm_project_t *proj);

/* ppm project builder functions. */
int ppm_project_init(ppm_project_t *proj,
        char *name,
        char *version,
        );
int ppm_project_add_dependency(ppm_project_t *proj,
        char *name,
        char *version);
int ppm_project_add_additional_repo(ppm_project_t *proj,
        char *url);
int ppm_project_complete(ppm_project_t *proj);

int ppm_project
int ppm_project_free(ppm_project_t *proj);
int ppm_project_resolve_deps(ppm_project_t *proj);



int install_package_files_checked(


#endif
