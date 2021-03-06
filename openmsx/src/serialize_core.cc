// $Id: serialize_core.cc 12803 2012-08-13 17:41:51Z m9710797 $

#include "serialize_core.hh"
#include "serialize.hh"
#include "MSXException.hh"
#include "StringOp.hh"
#include "likely.hh"

namespace openmsx {

void enumError(const std::string& str)
{
	throw MSXException("Invalid enum value: " + str);
}

void pointerError(unsigned id)
{
	throw MSXException(StringOp::Builder() <<
		"Couldn't find pointer in archive with id " << id);
}


static void versionError(const char* className, unsigned latestVersion, unsigned version)
{
	// note: the result of type_info::name() is implementation defined
	//       but should be ok to show in an error message
	throw MSXException(StringOp::Builder() <<
		"your openMSX installation is too old (state contains type '" <<
		className << "' with version " << version <<
		", while this openMSX installation only supports up to version " <<
		latestVersion << ").");
}

unsigned loadVersionHelper(MemInputArchive& /*ar*/, const char* /*className*/,
                           unsigned /*latestVersion*/)
{
	UNREACHABLE; return 0;
}

unsigned loadVersionHelper(XmlInputArchive& ar, const char* className,
                           unsigned latestVersion)
{
	assert(ar.canHaveOptionalAttributes());
	unsigned version;
	if (!ar.findAttribute("version", version)) {
		return 1;
	}
	if (unlikely(version > latestVersion)) {
		versionError(className, latestVersion, version);
	}
	return version;
}

} // namespace openmsx
