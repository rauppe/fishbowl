#ifndef ENGINE_H
#define ENGINE_H

#include "../comm_database/database.h"
#include "../groups/group.h"
#include "../profiles/profile.h"

class Engine
{
public:
    Engine();

    ~Engine();

    void update_data();
    void load_data();

    void create_profile(QString username, QString firstName, QString lastName, int age, QString location, QString type, QDateTime dateCreated, QString description=0);
    void create_post(Profile *actor, Group *group, QString title, QString content);
    void create_comment(Profile *actor, Post *post, QString content);
    void create_comment_reply(Profile *actor, Post *post, PostComment *parentComment, QString content);
    void create_groupchat(Profile *actor, QString name, std::vector<Profile*> participants);
    void create_group(Profile *actor, QString name, QString description);
    void create_message(Profile *actor, GroupChat *groupchat, QString content);
    void create_fish(Profile *actor, QString name, int age, QString location, QString species, QString description);

    void join_group(Profile *actor, Group *group);
    void join_groupchat(Profile *actor, GroupChat *groupchat);

    void leave_group(Profile *actor, Group *group);
    void leave_groupchat(Profile *actor, GroupChat *groupchat);

    void edit_my_profile(Profile *actor, QString firstName, QString lastName, int age, QString location, QString description);
    void edit_my_fish(Profile *actor, Fish *fish, QString name, int age, QString location, QString species, QString description);
    void edit_my_password(Profile *actor, QString newPassword);
    void edit_group_description(Profile *actor, QString newDescription);
    void edit_post(Profile *actor, Post *post, QString newContent);
    void edit_comment(Profile *actor, PostComment *comment, QString newContent);

    void remove_from_group(Profile *actor, Group *group, Profile *groupMember);
    //void remove_from_groupchat(Profile *actor, GroupChat *groupchat, Profile *groupchatParticipant);

    void delete_post(Profile *actor, Post *post);
    void delete_comment(Profile *actor, PostComment *comment);
    void delete_groupchat(Profile *actor, GroupChat *groupchat);
    void delete_group(Profile *actor, Group *group);

    void ban_user(Profile *actor, Profile *user, Group *group);


private:
    Database *db;
    QString dateFormat;

    std::map<int, Profile*> profiles;
    std::map<int, Group*> groups;
    std::map<int, Post*> posts;
    std::map<int, GroupChat*> groupchats;

    std::vector<QString> profileFields;
    std::vector<QString> fishFields;
    std::vector<QString> groupFields;
    std::vector<QString> groupMemberFields;
    std::vector<QString> friendsFields;

    std::vector<QString> postFields;
    std::vector<QString> commentFields;
    std::vector<QString> groupchatFields;
    std::vector<QString> groupchatParticipantFields;
    std::vector<QString> messageFields;

    std::vector<QString> adminFields;
    std::vector<QString> bannedUserFields;


};

#endif // ENGINE_H
