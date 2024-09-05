// Code generated by protoc-gen-validate
// source: smurf.proto
// DO NOT EDIT!!!

#include "smurf.pb.validate.h"

#include "re2/re2.h"
#include <google/protobuf/message.h>
#include <google/protobuf/util/time_util.h>

namespace pgv {

namespace protobuf = google::protobuf;
namespace protobuf_wkt = google::protobuf;

namespace validate {
using std::string;

// define the regex for a UUID once up-front
const re2::RE2
    _uuidPattern("^[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}$");

pgv::Validator<::examplepb::Person> validator___examplepb__Person(
    static_cast<bool (*)(const ::examplepb::Person&, pgv::ValidationMsg*)>(::examplepb::Validate));
pgv::Validator<::examplepb::Person_Location> validator___examplepb__Person_Location(
    static_cast<bool (*)(const ::examplepb::Person_Location&, pgv::ValidationMsg*)>(
        ::examplepb::Validate));

} // namespace validate
} // namespace pgv

namespace examplepb {

// Validate checks the field values on ::examplepb::Person with the rules
// defined in the proto definition for this message. If any rules are
// violated, the return value is false and an error message is written to the
// input string argument.

const re2::RE2 _Person_Name_Pattern(re2::StringPiece("^[A-Za-z]+( [A-Za-z]+)*$",
                                                     sizeof("^[A-Za-z]+( [A-Za-z]+)*$") - 1));

bool Validate(const ::examplepb::Person& m, pgv::ValidationMsg* err) {
    (void)m;
    (void)err;

    if (m.id() <= 999) {
        {
            std::ostringstream msg("invalid ");
            msg << "PersonValidationError" << "." << "Id";
            msg << ": " << "value must be greater than 999";
            *err = msg.str();
            return false;
        }
    }

    throw pgv::UnimplementedException("C++ email address validation is not implemented");

    if (m.name().size() > 256) {
        {
            std::ostringstream msg("invalid ");
            msg << "PersonValidationError" << "." << "Name";
            msg << ": " << "value length must be at most 256 bytes";
            *err = msg.str();
            return false;
        }
    }

    {
        if (!RE2::FullMatch(re2::StringPiece(m.name().c_str(), m.name().size()),
                            _Person_Name_Pattern)) {
            {
                std::ostringstream msg("invalid ");
                msg << "PersonValidationError" << "." << "Name";
                msg << ": " << "value does not match regex pattern \"^[A-Za-z]+( [A-Za-z]+)*$\"";
                *err = msg.str();
                return false;
            }
        }
    }

    if (!m.has_home()) {
        {
            std::ostringstream msg("invalid ");
            msg << "PersonValidationError" << "." << "Home";
            msg << ": " << "value is required";
            *err = msg.str();
            return false;
        }
    }

    {
        pgv::ValidationMsg inner_err;
        if (m.has_home() && !pgv::BaseValidator::AbstractCheckMessage(m.home(), &inner_err)) {
            {
                std::ostringstream msg("invalid ");
                msg << "PersonValidationError" << "." << "Home";
                msg << ": " << "embedded message failed validation";
                msg << " | caused by " << inner_err;
                *err = msg.str();
                return false;
            }
        }
    }

    return true;
}

// Validate checks the field values on ::examplepb::Person_Location with the
// rules defined in the proto definition for this message. If any rules are
// violated, the return value is false and an error message is written to the
// input string argument.

bool Validate(const ::examplepb::Person_Location& m, pgv::ValidationMsg* err) {
    (void)m;
    (void)err;

    if (m.lat() < -90 || m.lat() > 90) {
        {
            std::ostringstream msg("invalid ");
            msg << "LocationValidationError" << "." << "Lat";
            msg << ": " << "value must be inside range [-90, 90]";
            *err = msg.str();
            return false;
        }
    }

    if (m.lng() < -180 || m.lng() > 180) {
        {
            std::ostringstream msg("invalid ");
            msg << "LocationValidationError" << "." << "Lng";
            msg << ": " << "value must be inside range [-180, 180]";
            *err = msg.str();
            return false;
        }
    }

    return true;
}

} // namespace examplepb
