use theater;

go

IF OBJECT_ID ('stagings_genders', 'V') IS NOT NULL
DROP VIEW stagings_genders;

go

create view stagings_genders
as
(select staging.id, sum(case when gender.description = N'Ж' then 1 else 0 end) as sumF,
sum(case when gender.description = N'М' then 1 else 0 end) as sumM from staging, role_staging, role, gender
where staging.id = role_staging.staging
and role_staging.role = role.id
and role.gender = gender.id
--and gender.description = N'Ж'
group by staging.id
)

go

create procedure performanceSuffixAdd
(
@performanceID int
)
as
declare @oldName nvarchar(1500);

select @oldName = [name] from performance where id = @performanceID

declare @suffix nvarchar(1500);
select @suffix = N' (в традициях времен Шекспира)';

case when (substr(@oldName, len(@oldName) - len(@suffix), len(@suffix)) = @suffix)
then
	update performance set description = descri
else
end

go

select * from stagings_genders