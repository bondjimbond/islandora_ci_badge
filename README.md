# Islandora Cultural Institution Notices

## Introduction

Islandora CI Notices provides a block containing all the pieces required for an Attribution Incomplete notice as required by localcontexts.org.

Information about the notice can be found at https://localcontexts.org/notice/attribution-incomplete/.

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Islandora Solr](https://github.com/islandora/islandora_solr)
* [Islandora Badges](../../)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

Configuration path is admin/islandora/tools/badges/ci_badge (Administration > Islandora > Islandora Utility Modules > Islandora Badges Configuration > Cultural Institution Badge).

* Solr field for the CI Attribution Incomplete information:
  * Use a single-valued Solr string (ending in `_s`).
* Text to identify if an object requires the Attribution Incomplete label:
  * The module searches for this string in the value of the above Solr field. Exact match required.
* HTML element for the badge title:
  * The module generates a block with title, image, and text as required by Local Contexts. The HTML element for the title is customizable.

## Metadata

You can use any element for your Attribution Incomplete notice, so long as it generates a Solr field. Default behaviour assumes you are using the following metadata, 
which should generate the default Solr field:

`<note type="CI Notice">` to generate the field `mods_note_CI_Notice_s`.

## Troubleshooting/Issues

Having problems or solved a problem? Check out the Islandora google groups for a solution.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

## Maintainers/Sponsors

Current maintainers:

* [Brandon Weigel](https://github.com/bondjimbond)

## Development

If you would like to contribute to this module, open an issue and/or a pull request.

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
