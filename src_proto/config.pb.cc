// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: src_proto/config.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "src_proto/config.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace protocol {

namespace {

const ::google::protobuf::Descriptor* Config_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Config_reflection_ = NULL;
const ::google::protobuf::Descriptor* Obj2dString_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Obj2dString_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_src_5fproto_2fconfig_2eproto() {
  protobuf_AddDesc_src_5fproto_2fconfig_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "src_proto/config.proto");
  GOOGLE_CHECK(file != NULL);
  Config_descriptor_ = file->message_type(0);
  static const int Config_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Config, version_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Config, labels_),
  };
  Config_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Config_descriptor_,
      Config::default_instance_,
      Config_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Config, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Config, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Config));
  Obj2dString_descriptor_ = file->message_type(1);
  static const int Obj2dString_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Obj2dString, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Obj2dString, text_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Obj2dString, x_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Obj2dString, y_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Obj2dString, rad_),
  };
  Obj2dString_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Obj2dString_descriptor_,
      Obj2dString::default_instance_,
      Obj2dString_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Obj2dString, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Obj2dString, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Obj2dString));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_src_5fproto_2fconfig_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Config_descriptor_, &Config::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Obj2dString_descriptor_, &Obj2dString::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_src_5fproto_2fconfig_2eproto() {
  delete Config::default_instance_;
  delete Config_reflection_;
  delete Obj2dString::default_instance_;
  delete Obj2dString_reflection_;
}

void protobuf_AddDesc_src_5fproto_2fconfig_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026src_proto/config.proto\022\010protocol\"@\n\006Co"
    "nfig\022\017\n\007version\030\001 \002(\t\022%\n\006labels\030\003 \003(\0132\025."
    "protocol.Obj2dString\"L\n\013Obj2dString\022\014\n\004n"
    "ame\030\001 \002(\t\022\014\n\004text\030\002 \002(\t\022\t\n\001x\030\003 \002(\002\022\t\n\001y\030"
    "\004 \002(\002\022\013\n\003rad\030\005 \002(\002", 178);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "src_proto/config.proto", &protobuf_RegisterTypes);
  Config::default_instance_ = new Config();
  Obj2dString::default_instance_ = new Obj2dString();
  Config::default_instance_->InitAsDefaultInstance();
  Obj2dString::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_src_5fproto_2fconfig_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_src_5fproto_2fconfig_2eproto {
  StaticDescriptorInitializer_src_5fproto_2fconfig_2eproto() {
    protobuf_AddDesc_src_5fproto_2fconfig_2eproto();
  }
} static_descriptor_initializer_src_5fproto_2fconfig_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Config::kVersionFieldNumber;
const int Config::kLabelsFieldNumber;
#endif  // !_MSC_VER

Config::Config()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.Config)
}

void Config::InitAsDefaultInstance() {
}

Config::Config(const Config& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.Config)
}

void Config::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  version_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Config::~Config() {
  // @@protoc_insertion_point(destructor:protocol.Config)
  SharedDtor();
}

void Config::SharedDtor() {
  if (version_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete version_;
  }
  if (this != default_instance_) {
  }
}

void Config::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Config::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Config_descriptor_;
}

const Config& Config::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_src_5fproto_2fconfig_2eproto();
  return *default_instance_;
}

Config* Config::default_instance_ = NULL;

Config* Config::New() const {
  return new Config;
}

void Config::Clear() {
  if (has_version()) {
    if (version_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      version_->clear();
    }
  }
  labels_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Config::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.Config)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string version = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_version()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->version().data(), this->version().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "version");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_labels;
        break;
      }

      // repeated .protocol.Obj2dString labels = 3;
      case 3: {
        if (tag == 26) {
         parse_labels:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_labels()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_labels;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.Config)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.Config)
  return false;
#undef DO_
}

void Config::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.Config)
  // required string version = 1;
  if (has_version()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->version().data(), this->version().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "version");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->version(), output);
  }

  // repeated .protocol.Obj2dString labels = 3;
  for (int i = 0; i < this->labels_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->labels(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.Config)
}

::google::protobuf::uint8* Config::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.Config)
  // required string version = 1;
  if (has_version()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->version().data(), this->version().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "version");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->version(), target);
  }

  // repeated .protocol.Obj2dString labels = 3;
  for (int i = 0; i < this->labels_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->labels(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.Config)
  return target;
}

int Config::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string version = 1;
    if (has_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->version());
    }

  }
  // repeated .protocol.Obj2dString labels = 3;
  total_size += 1 * this->labels_size();
  for (int i = 0; i < this->labels_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->labels(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Config::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Config* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Config*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Config::MergeFrom(const Config& from) {
  GOOGLE_CHECK_NE(&from, this);
  labels_.MergeFrom(from.labels_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_version()) {
      set_version(from.version());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Config::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Config::CopyFrom(const Config& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Config::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (!::google::protobuf::internal::AllAreInitialized(this->labels())) return false;
  return true;
}

void Config::Swap(Config* other) {
  if (other != this) {
    std::swap(version_, other->version_);
    labels_.Swap(&other->labels_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Config::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Config_descriptor_;
  metadata.reflection = Config_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Obj2dString::kNameFieldNumber;
const int Obj2dString::kTextFieldNumber;
const int Obj2dString::kXFieldNumber;
const int Obj2dString::kYFieldNumber;
const int Obj2dString::kRadFieldNumber;
#endif  // !_MSC_VER

Obj2dString::Obj2dString()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.Obj2dString)
}

void Obj2dString::InitAsDefaultInstance() {
}

Obj2dString::Obj2dString(const Obj2dString& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.Obj2dString)
}

void Obj2dString::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  text_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  x_ = 0;
  y_ = 0;
  rad_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Obj2dString::~Obj2dString() {
  // @@protoc_insertion_point(destructor:protocol.Obj2dString)
  SharedDtor();
}

void Obj2dString::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (text_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete text_;
  }
  if (this != default_instance_) {
  }
}

void Obj2dString::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Obj2dString::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Obj2dString_descriptor_;
}

const Obj2dString& Obj2dString::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_src_5fproto_2fconfig_2eproto();
  return *default_instance_;
}

Obj2dString* Obj2dString::default_instance_ = NULL;

Obj2dString* Obj2dString::New() const {
  return new Obj2dString;
}

void Obj2dString::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Obj2dString*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 31) {
    ZR_(x_, rad_);
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
    if (has_text()) {
      if (text_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        text_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Obj2dString::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.Obj2dString)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string name = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_text;
        break;
      }

      // required string text = 2;
      case 2: {
        if (tag == 18) {
         parse_text:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_text()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->text().data(), this->text().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "text");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(29)) goto parse_x;
        break;
      }

      // required float x = 3;
      case 3: {
        if (tag == 29) {
         parse_x:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &x_)));
          set_has_x();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(37)) goto parse_y;
        break;
      }

      // required float y = 4;
      case 4: {
        if (tag == 37) {
         parse_y:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &y_)));
          set_has_y();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(45)) goto parse_rad;
        break;
      }

      // required float rad = 5;
      case 5: {
        if (tag == 45) {
         parse_rad:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &rad_)));
          set_has_rad();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.Obj2dString)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.Obj2dString)
  return false;
#undef DO_
}

void Obj2dString::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.Obj2dString)
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->name(), output);
  }

  // required string text = 2;
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "text");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->text(), output);
  }

  // required float x = 3;
  if (has_x()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(3, this->x(), output);
  }

  // required float y = 4;
  if (has_y()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(4, this->y(), output);
  }

  // required float rad = 5;
  if (has_rad()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(5, this->rad(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.Obj2dString)
}

::google::protobuf::uint8* Obj2dString::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.Obj2dString)
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
  }

  // required string text = 2;
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "text");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->text(), target);
  }

  // required float x = 3;
  if (has_x()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(3, this->x(), target);
  }

  // required float y = 4;
  if (has_y()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(4, this->y(), target);
  }

  // required float rad = 5;
  if (has_rad()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(5, this->rad(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.Obj2dString)
  return target;
}

int Obj2dString::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string name = 1;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // required string text = 2;
    if (has_text()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->text());
    }

    // required float x = 3;
    if (has_x()) {
      total_size += 1 + 4;
    }

    // required float y = 4;
    if (has_y()) {
      total_size += 1 + 4;
    }

    // required float rad = 5;
    if (has_rad()) {
      total_size += 1 + 4;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Obj2dString::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Obj2dString* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Obj2dString*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Obj2dString::MergeFrom(const Obj2dString& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_text()) {
      set_text(from.text());
    }
    if (from.has_x()) {
      set_x(from.x());
    }
    if (from.has_y()) {
      set_y(from.y());
    }
    if (from.has_rad()) {
      set_rad(from.rad());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Obj2dString::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Obj2dString::CopyFrom(const Obj2dString& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Obj2dString::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001f) != 0x0000001f) return false;

  return true;
}

void Obj2dString::Swap(Obj2dString* other) {
  if (other != this) {
    std::swap(name_, other->name_);
    std::swap(text_, other->text_);
    std::swap(x_, other->x_);
    std::swap(y_, other->y_);
    std::swap(rad_, other->rad_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Obj2dString::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Obj2dString_descriptor_;
  metadata.reflection = Obj2dString_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol

// @@protoc_insertion_point(global_scope)