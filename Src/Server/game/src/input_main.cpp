//Find
	if (buflen > 1 && *buf == '/')
	{
		interpret_command(ch, buf + 1, buflen - 1);
		return iExtraLen;
	}
	
///Add
#ifdef CHAT_PM
	std::string findstr(buf);
	if (findstr.at(0) == '@') {
		findstr = findstr.substr(1); // or findstr.erase(0,1);
		int pos = findstr.find(" ");
		std::string message = findstr.substr(pos + 1), chname = findstr.substr(0,pos);
		LPCHARACTER stch = CHARACTER_MANAGER::instance().FindPC(chname.c_str());
		stch ? stch != ch ? stch->ChatPacket(CHAT_TYPE_WHISPER, "%s sent a message: %s", ch->GetName(), message.c_str()) : ch->ChatPacket(CHAT_TYPE_INFO, "target is you") : ch->ChatPacket(CHAT_TYPE_INFO, "%s isn't exist.", chname.c_str());
		return (iExtraLen);
	}
#endif