// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <boost/filesystem.hpp>
#include <ostream>
#include <iostream>

using namespace boost;

class account
{

 public:

  friend std::ostream &operator<<(std::ostream &out, const account &ac);

  /* void SetBrokerName(std::string broker_name);
  void SetFilenames(std::vector<std::string> filenames);
  void SetAccountNumber(std::string number_account);
  void SetLastdate(std::string lastdate);

  std::string GetBrokerName();
  std::vector<std::string> GetFilenames();
  std::string GetAccountNumber();
  std::string GetLastdate(); */

  std::string broker_name;
  std::vector<std::string> filenames;
  std::string number_account;
  std::string lastdate;

};

class analyzer
{

 public:

  friend std::ostream &operator<<(std::ostream &out, const analyzer &a);
  void parse_dir_info(const filesystem::path&path_dir, const std::string &broker);
  std::string get_number_account(const std::string &filename);
  bool check_filename(const filesystem::path&path_file);
  std::string get_date(const std::string& filename) const;
  void set_lastdates();
  analyzer(const filesystem::path &path_ftp);
  ~analyzer();

 private:

  filesystem::path path_to_ftp;
  std::vector<class account*> accounts;

};

#endif // INCLUDE_HEADER_HPP_
