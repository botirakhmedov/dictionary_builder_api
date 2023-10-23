#ifndef WordDto_hpp
#define WordDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class WordDto : public oatpp::DTO {
  
  DTO_INIT(WordDto, DTO)

  DTO_FIELD(Int32, id);
  DTO_FIELD(String, wordName, "wordname");
  DTO_FIELD(String, wordWrap, "wordwrap");
};

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
